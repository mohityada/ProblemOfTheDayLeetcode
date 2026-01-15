class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int length = 0, width = 0;

        int i = 0, hBarsLength = hBars.size();
        while(i < hBarsLength){
            int num = hBars[i];
            if(num == 1 || num == n + 2){
                i++;
                continue;
            }
            int j = i;
            while(i < hBarsLength && num++ == hBars[i]){
                i++;
            }
            length = max(length, i - j);
        }

        i = 0; 
        int vBarsLength = vBars.size();
        while(i < vBarsLength){
            int num = vBars[i];
            if(num == 1 || num == m + 2){
                i++;
                continue;
            }
            int j = i;
            while(i < vBarsLength && num++ == vBars[i]){
                i++;
            }
            width = max(width, i - j);
        }
        int square = min(length + 1, width + 1);
        return square * square;
    }
};
