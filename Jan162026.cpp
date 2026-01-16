class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int ans = -1, i = 0;
        int MOD = 1e9 + 7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        int hFencesSize = hFences.size(), vFencesSize = vFences.size();    
        
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> sethFences;
        while(i < hFencesSize){
            int rem;
            for(int j = 0; j < i; j++){
                rem = hFences[i] - hFences[j];
                sethFences.insert(rem);
            }
            i++;
        }

        i = 0;
        while(i < vFencesSize){
            int rem;
            for(int j = 0; j < i; j++){
                rem = vFences[i] - vFences[j];
                if(sethFences.find(rem) != sethFences.end()){
                    ans = max(ans, rem);
                } 
            }
            i++;
        }
        if(ans == -1) return ans;
        return (int)((1LL * ans * ans)%MOD);
    }
};
