#include<stack>

using namespace std;

// 232. Implement Queue using Stacks
// Using two stacks. One for input, the other one for the pop and peek. When pop or peek, if the outStack is empty, reverse the 
// elements in the inStack and put them into the outStack.

class MyQueue {


private:
    stack<int> inStack;
    stack<int> outStack;
    void trans(){
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if(outStack.empty()) trans();
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    
    int peek() {
        if(outStack.empty()) trans();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
    
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */