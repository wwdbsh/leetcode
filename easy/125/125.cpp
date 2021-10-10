#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for(int l = 0, r = s.length()-1; l <= r; l++, r--){
            while(l < r && !isLetter(s, l)) l++;
            while(l < r && !isLetter(s, r)) r--;
            if(tolower(s[l]) != tolower(s[r])) return false;
        }
        return true;
    }
private:
    bool isLetter(string s, int index){
        return (
            (s[index] >= 'a' && s[index] <= 'z') ||
            (s[index] >= 'A' && s[index] <= 'Z' ) ||
            (s[index] >= '0' && s[index] <= '9')
        );
    }
};