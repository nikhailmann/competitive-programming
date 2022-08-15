class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] ransomChecker = new int[26];
        int[] magChecker = new int[26];
        
        for (int i = 0; i < ransomNote.length(); i++) {
            char rCurr = ransomNote.charAt(i);
            int rC = ((int) rCurr)-97;
            ransomChecker[rC]++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            char mCurr = magazine.charAt(i);
            int mC = ((int) mCurr)-97;
            magChecker[mC]++;
        }
        for (int i = 0; i < 26; i++) {
            if (ransomChecker[i] > magChecker[i]) {
                return false;
            }
        }
        return true;
    }
}

// you can also keep only one array and do ++ for ransom loop and -- for magazine loop
