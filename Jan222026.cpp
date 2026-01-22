class Solution {
public:
    int minimumPairRemoval(vector<int>& num) {
        long long n = num.size();
        vector<long long> nums(num.begin(), num.end());
        vector<long long> prev(n), next(n);
        for (long long i = 0; i < n; i++){
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<>> pq;
        // set<pair<long long, long long>> storeValidSums;

        long long badPairs = 0, operations = 0, INVALID = LLONG_MIN;

        vector<long long> currentPairSums(n, INVALID);
        for(long long i = 0; i < n - 1; i++){
            if(nums[i] > nums[i+1]) badPairs++;
            pq.push({nums[i] + nums[i+1], i});
            currentPairSums[i] = nums[i] + nums[i+1];
            // storeValidSums.insert({nums[i] + nums[i+1], i});
        }

        
        while(badPairs > 0 && !pq.empty()){
            vector<long long> top = pq.top();
            pq.pop();
            long long i = top[1];
            long long j = next[i];
            if(j >= n) continue;
            if(currentPairSums[i] != top[0]){
                continue;
            }

            // storeValidSums.erase({top[0], i});

            if(nums[i] > nums[j]) badPairs--;
            
            if(prev[i] >= 0){
                if(nums[prev[i]] > nums[i]) badPairs--;
                // storeValidSums.erase({nums[prev[i]] + nums[i], prev[i]});
                currentPairSums[prev[i]] = INVALID;
            }

            if(next[j] < n){
                if(nums[j] > nums[next[j]]) badPairs--;
                // storeValidSums.erase({nums[j] + nums[next[j]], j});
                currentPairSums[j] = INVALID;
            }
            

            nums[i] += nums[j];
            currentPairSums[i] = INVALID;
            currentPairSums[j] = INVALID;
            j = next[j];
            next[i] = j;

            if(j < n){
                prev[j] = i;
            }

            if(j < n){
                if(nums[j] < nums[i]) badPairs++;
                // storeValidSums.insert({nums[i] + nums[j], i});
                pq.push({nums[i] + nums[j], i});
                currentPairSums[i] = nums[i] + nums[j];
            }
            
            if(prev[i] >= 0){
                if(nums[prev[i]] > nums[i]) badPairs++;
                // storeValidSums.insert({nums[prev[i]] + nums[i], prev[i]});
                pq.push({nums[prev[i]] + nums[i], prev[i]});
                currentPairSums[prev[i]] = nums[prev[i]] + nums[i];
            }  
            operations++;
        }
        
        return (int)operations;
    }
};

// int main(){
//     Solution sol;
//     vector<int> v = {3,4,1,1,-3,2,4,3};
//     cout << sol.minimumPairRemoval(v) << "\n";
//     return 0;
// }
