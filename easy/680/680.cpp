#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        return isPalindrome(s, 0, s.length()-1, 0);
    }
private:
    bool isPalindrome(string s, int left, int right, int mismatch){
        if(mismatch > 1){
            return false;
        }
        while(left < right){
            if(s[left] != s[right]){
                return isPalindrome(s, left+1, right, mismatch+1) || isPalindrome(s, left, right-1, mismatch+1);
            }
            left++;
            right--;
        }
        return true;
    }
};