#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
public:
    stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        this->st.push(val);
    }
    
    void pop() {
        this->st.pop();
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        int min_val = this->st.top();
        vector<int> temp;
        temp.push_back(this->st.top());
        this->st.pop();
        while(!this->st.empty()){
            int top = this->st.top();
            min_val = min(min_val, top);
            temp.push_back(top);
            this->st.pop();
        }
        for(int i = temp.size()-1; i >= 0; i--){
            this->st.push(temp[i]);
        }
        return min_val;
    }
};