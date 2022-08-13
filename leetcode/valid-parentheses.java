class Solution {
    public boolean isValid(String s) {
        Stack<Character> charStack = new Stack();
        
        for (Integer i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (curr == '(' || curr == '{' || curr == '[') {
                charStack.push(curr);
            } else if (curr == ')') {
                if (charStack.empty() || charStack.pop() != '(') {
                    return false;
                }
            } else if (curr == '}') {
                if (charStack.empty() || charStack.pop() != '{') {
                    return false;
                }
            } else if (curr == ']') {
                if (charStack.empty() || charStack.pop() != '[') {
                    return false;
                }
            }
        }
        if (charStack.empty()) return true;
        return false;
    }
}
