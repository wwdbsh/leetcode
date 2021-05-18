#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int idx1 = num1.length()-1;
        int idx2 = num2.length()-1;
        int carry = 0;
        string ans;
        while(idx1 >= 0 || idx2 >= 0){
            int sum = carry;
            if(idx1 >= 0) sum += (int)(num1[idx1--]-'0');
            if(idx2 >= 0) sum += (int)(num2[idx2--]-'0');
            carry = sum/10;
            ans = to_string(sum%10) + ans;
        }
        return carry == 0 ? ans : to_string(carry) + ans;
    }
};