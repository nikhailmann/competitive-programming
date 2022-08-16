class Solution {
    public int longestPalindrome(String s) {
        int[] letterTracker = new int[58]; //bc ascii of Z is 090 but a is 097
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            int index = ((int) a) - 65;
            letterTracker[index]++;
        }
        int longestOdd = 0;
        int ans = 0;
        boolean foundOdd = false;
        for (int i = 0; i < letterTracker.length; i++) {
            if (letterTracker[i] %2 == 0) {
                ans += letterTracker[i];
            } else {
                foundOdd = true;
                if (letterTracker[i] > longestOdd) {
                    ans += letterTracker[i]-1;
                }
            }
        }
        if (foundOdd) return ans+1;
        return ans;
    }
}
