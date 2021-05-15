#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == ')' || c == '}' || c == ']'){
                if(ss.empty()){
                    return false;
                }
                switch(c){
                    case ')':
                        if(ss.top() != '(')
                            return false;
                        break;
                    case '}':
                        if(ss.top() != '{')
                            return false;
                        break;
                    case ']':
                        if(ss.top() != '[')
                            return false;
                }
                ss.pop();
            }else{
                ss.push(c);
            }
        }
        return ss.empty() ? true : false;
    }
};