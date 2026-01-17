class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size(); 

        vector<pair<int, pair<int, int>>> bottomLeftPro(n); // x, y, idx

        for(int i = 0; i < n; i++){
            bottomLeftPro[i] = {bottomLeft[i][0], {bottomLeft[i][1], i}};
        }

        sort(bottomLeftPro.begin(), bottomLeftPro.end());
        long long maxArea = 0L;
        for(int i = 0; i < n; i++){
            int xibottom = bottomLeftPro[i].first;
            int yibottom = bottomLeftPro[i].second.first;

            int topIdxForI = bottomLeftPro[i].second.second;
            
            int xitop = topRight[topIdxForI][0];
            int yitop = topRight[topIdxForI][1];
            for(int j = i + 1; j < n; j++){    
                int xjbottom = bottomLeftPro[j].first;
                int yjbottom = bottomLeftPro[j].second.first;

                int topIdxForJ = bottomLeftPro[j].second.second;

                int xjtop = topRight[topIdxForJ][0];
                int yjtop = topRight[topIdxForJ][1];

                if(xitop <= xjbottom) break;

                if(yitop <= yjbottom || yibottom >= yjtop){
                    continue;
                }


                long long width = min(xitop, xjtop) - xjbottom;
                long long height = min(yitop, yjtop) - max(yibottom, yjbottom);
                long long side = min(width, height);
                maxArea = max(maxArea, side * side);
            }
        }
        return maxArea;
    }
};
