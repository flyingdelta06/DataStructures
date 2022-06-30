package inJava.stack;

public class example {
    // All Methods:
    // peek(); --> returns the top of stack;
    // push(int val) --> push an element val into the stack
    // pop() --> remove and return the element at the top of the stack
    // Constructor
    // new stackA() --> creates an empty stack with maxSize of 100
    // new stackA(int size) --> creates an empty stack with n = size elements
    public static void main(String[] args){
        stackA myStack = new stackA();
        myStack.push(15);
        myStack.push(16);
        System.out.println(myStack.peek()); // 16
        myStack.pop();
        System.out.println(myStack.peek()); // 15
    }
}
