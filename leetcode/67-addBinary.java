class Solution {
    public String addBinary(String a, String b) {
        StringBuilder ans = new StringBuilder();
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        
        while (i>=0 || j>= 0) {
            int sum = carry;
            if (i>=0) sum += a.charAt(i) - '0';
            if (j>=0) sum += b.charAt(j) - '0';
            ans.append(sum%2);
            carry = sum/2;
            i--;
            j--;
        }
        
        if (carry > 0) {
            ans.append(carry);
        }
        return ans.reverse().toString();
        
    }
}

/** fails for longer answers
class Solution {
    public String addBinary(String a, String b) {
        int a1 = binaryToInt(a);
        int b1 = binaryToInt(b);
        int res = a1 + b1;
        return Integer.toBinaryString(res);
    }
    
    public int binaryToInt(String a) {
        int ans = 0;
        int place = 0;
        for (int i = a.length()-1; i >= 0; i--) {
            char x = a.charAt(i);
            if (x == '1') {
                ans += Math.pow(2, place);
            }
            place++;
        }
        return ans;
        
    }
}
**/
