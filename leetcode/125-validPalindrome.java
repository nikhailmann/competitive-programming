class Solution {
    public boolean isPalindrome(String s) {
        String test = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c) || Character.isLetter(c)) {
                test += c;
            }
        }
        test = test.toLowerCase();
        for (int lp = 0, rp = test.length() - 1; lp <= rp; lp++) {
            if (test.charAt(lp) != test.charAt(rp)) {
                return false;
            }
            rp--;
        }
        return true;
    }
}
