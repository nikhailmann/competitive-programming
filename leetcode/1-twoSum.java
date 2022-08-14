class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap();
        for (int i = 0; i < nums.length; i++) {
            int target2 = target - nums[i];
            if (mp.containsKey(target2)) {
                return new int[] {mp.get(target2), i};
            }
            mp.put(nums[i], i);
        }
        return new int[] {0, 0};
    }
}
