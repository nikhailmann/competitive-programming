class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        int best = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum = Math.max(nums[i], sum + nums[i]);
            best = Math.max(best, sum);
        }
        return best;
    }
}
