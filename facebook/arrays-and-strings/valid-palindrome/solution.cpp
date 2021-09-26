#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                ss += tolower(c);
            }
        }
        for(int l = 0, r = ss.length()-1; l <= r; l++, r--){
            if(ss[l] != ss[r]){
                return false;
            }
        }
        return true;
    }
};