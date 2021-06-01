#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if(s.length() == 1){
            return convertToInt(s[0]);
        }
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            st.push(s[i]);
        }
        int number = 0;
        char cur = st.top(); st.pop();
        while(!st.empty()){
            int temp = convertToInt(cur);
            if(
                ((cur == 'V' || cur == 'X') && st.top() == 'I') ||
                ((cur == 'L' || cur == 'C') && st.top() == 'X') ||
                ((cur == 'D' || cur == 'M') && st.top() == 'C') 
            ){
                temp -= convertToInt(st.top()); st.pop();
            }
            number += temp;
            if(st.empty()){
                cur = '\0';
                break;
            }
            cur = st.top(); st.pop();
        }
        return cur == '\0' ? number : number + convertToInt(cur);
    }
private:
    int convertToInt(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            default: return 1000; // M
        }
    }
};