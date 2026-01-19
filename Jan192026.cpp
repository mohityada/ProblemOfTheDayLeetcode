class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> rowsum(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            rowsum[i][0] = mat[i][0];
            for(int j = 1; j < m; j++){
                rowsum[i][j] = rowsum[i][j-1] + mat[i][j];
            }
        }
        int maxSideLength = 0;
        int maxSize = min(n, m);
      
        // check for all possible sizes
        for(int size = 1; size <= maxSize; size++){
            for(int j = size - 1; j < m; j++){
                int sum = 0;
                for(int i = 0; i < n; i++){
                    sum = sum + rowsum[i][j] - (j - (size - 1) <= 0 ? 0 : rowsum[i][j - size]); // take for i -> (i - size) to remove redundant columns

                    sum = sum - (i - (size - 1) <= 0 ? 0 : (rowsum[i - size][j] -  (j - (size - 1) <= 0 ? 0 : rowsum[i - size][j - size] ))); // to remove redundant rows 

                    if(sum <= threshold && i >= size - 1){
                        maxSideLength = size;
                        break;
                    }
                }
                if(maxSideLength == size){
                    break;
                }
            }
        }
        return maxSideLength;
    }
};
