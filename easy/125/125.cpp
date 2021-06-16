#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c >= 97 && c <= 122){
                ss += c;
            }else if(c >= 65 && c <= 90){
                ss += tolower(c);
            }else if(c >= 48 && c <= 57){
                ss += c;
            }
        }
        for(int left = 0, right = ss.length()-1; left <= right; left++, right--){
            if(ss[left] != ss[right]){
                return false;
            }
        }
        return true;
    }
};