class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(num == 2){
                ans[i] = -1;
                continue;
            }
            int bit = 0;
            while(bit < 32){
                int currBit = (1 << bit) & num;
                if(currBit == 0){
                    ans[i] = num & ~(1 << (bit-1));
                    break;
                }
                bit++;
            }
        }
        return ans;
    }
};
