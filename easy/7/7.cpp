#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        stack<char> s;
        string str_x = to_string(x);
        int start = str_x[0] == '-' ? 1 : 0;
        for(int i = start; i < str_x.length(); i++){
            s.push(str_x[i]);
        }
        long long ans = 0, factor = pow(10, s.size()-1);
        while(!s.empty()){
            ans += (int)(s.top()-'0')*factor;
            factor /= 10;
            s.pop();
        }
        ans = start == 1 ? ans*-1 : ans;
        return ans >= INT_MIN && ans <= INT_MAX ? ans : 0;
    }
};