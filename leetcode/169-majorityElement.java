class Solution {
    public int majorityElement(int[] nums) { //moore majority vote algorithm
        int ret = nums[0];
        int count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (count == 0) {
                ret = nums[i];
            }
            if (nums[i] == ret) {
                count++;
            } else {
                count--;
            }
        }
        return ret;
    }
}
    

/*
class Solution { // brute force.. you can also sort the array and return the middle element, a lot of ways to do this
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int bestCount = 0;
        int ret = 0;
        for (int i = 0; i < nums.length; i++) {
            int key = nums[i];
            mp.merge(key, 1, Integer::sum);
            if (mp.get(key) > bestCount) {
                bestCount = mp.get(key);
                ret = key;
            }
        }
        return ret;
    }
}
*/
