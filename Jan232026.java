class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int left = 0, right = n-1;
        int minSum = 0;
        while(left < right){
            minSum = Math.max(minSum, nums[left] + nums[right]);
            left++;
            right--;
        }
        return minSum;
    }
}
