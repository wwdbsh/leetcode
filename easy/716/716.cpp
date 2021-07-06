#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> max_st;
    MaxStack() {
        
    }
    
    void push(int x) {
        int max = max_st.empty() ? x : max_st.top();
        if(max > x){
            max_st.push(max);
        }else{
            max_st.push(x);
        }
        st.push(x);
    }
    
    int pop() {
        max_st.pop();
        int rt = st.top();
        st.pop();
        return rt;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return max_st.top();
    }
    
    int popMax() {
        int max = peekMax();
        stack<int> buffer;
        while(top() != max){
            buffer.push(pop());
        }
        pop();
        while(!buffer.empty()){
            push(buffer.top());
            buffer.pop();
        }
        return max;
    }
};
