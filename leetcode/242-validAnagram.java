class Solution {
    public boolean isAnagram(String s, String t) {
        char temp1[] = s.toCharArray();
        char temp2[] = t.toCharArray();
        Arrays.sort(temp1);
        Arrays.sort(temp2);
        String s2 = new String(temp1);
        String t2 = new String(temp2);
        return (s2.equals(t2));
    }
}
