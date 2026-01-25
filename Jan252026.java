class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int minDiff = Integer.MAX_VALUE;
        int i = k-1;
        if(k == 1) return 0; 
        while (i < n) {
            minDiff = Math.min(nums[i] - nums[i-k+1], minDiff);
            i++;
        }
        return minDiff;
    }
}
