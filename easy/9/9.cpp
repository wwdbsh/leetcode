#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        for(int l = 0, r = num.length()-1; l <= r; l++, r--){
            if(num[l] != num[r]){
                return false;
            }
        }
        return true;
    }
};