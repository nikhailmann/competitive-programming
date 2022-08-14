class Solution {
    public int search(int[] nums, int target) {
        int lp = 0, rp = nums.length-1;
        while (lp <= rp) {
            int mid = (lp+rp)/2;
            int curr = nums[mid];
            if (curr == target) {
                return mid;
            } else if (curr > target) {
                rp = mid - 1;
            } else {
                lp = mid + 1;
            }
        }
        return -1;
    }
}
