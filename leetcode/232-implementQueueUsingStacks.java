class MyQueue {
    
    Stack<Integer> stack1 = new Stack();
    Stack<Integer> stack2 = new Stack();
    public MyQueue() {
        
    }
    
    public void push(int x) {
        this.stack1.push(x);
    }
    
    public int pop() { //all calls are valid so don't worry
        if (this.stack2.isEmpty()) {
            while (!this.stack1.isEmpty()) {
                this.stack2.push(stack1.pop());
            }
        }
        return this.stack2.pop();
        
    }
    
    public int peek() {
        if (this.stack2.isEmpty()) {
            while (!this.stack1.isEmpty()) {
                this.stack2.push(stack1.pop());
            }
        }
        return this.stack2.peek();
    }
    
    public boolean empty() {
        if (this.stack1.isEmpty() && this.stack2.isEmpty()) {
            return true;
        }
        return false;
        
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
