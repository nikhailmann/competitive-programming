class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        int currMin = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < currMin) currMin = prices[i];
            if (profit < prices[i] - currMin) profit = prices[i] - currMin;
            //currMin = Math.min(currMin, prices[i]);
            //profit = Math.max(profit, prices[i] - currMin);
        }
        return profit;
    }
}
