class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[46];
        dp[0] = 1;
        int[] steps = {1, 2};
        for (int i = 1; i <= n; i++) {
            for (int j : steps) {
                if (i - j >= 0) {
                    dp[i] += dp[i-j];
                }
            }
        }
        return dp[n];
    }
}
