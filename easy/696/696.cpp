#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero = 0, one = 0, flip = 0, ans = 0;
        s[0] == '0' ? zero++ : one++;
        for(int i = 1; i < s.length(); i++){
            if(s[i-1] == s[i]){
                s[i] == '0' ? zero++ : one++;
            }else{
                flip++;
                if(flip%2 == 0){
                    ans += min(zero, one);
                    s[i] == '0' ? zero = 1 : one = 1;
                    flip++;
                }else{
                    s[i] == '0' ? zero++ : one++;
                }
            }
        }
        return ans + min(zero, one);
    }
};