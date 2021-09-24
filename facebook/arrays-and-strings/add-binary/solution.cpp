#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string l = a, s = b;
        if(a.length() < b.length()){
            l = b;
            s = a;
        }
        bool carry = false;
        string ans = "";
        for(int i = s.length()-1; i >= 0; i--){
            char bit1 = s[i];
            char bit2 = l[i+(l.length()-s.length())];
            if(bit1 == '0' && bit2 == '0'){
                if(carry){
                    ans = '1' + ans;
                    carry = false;
                }else{
                    ans = '0' + ans;
                }
            }else if(bit1 == '0' && bit2 == '1'){
                if(carry){
                    ans = '0' + ans;
                }else{
                    ans = '1' + ans;
                }
            }else if(bit1 == '1' && bit2 == '0'){
                if(carry){
                    ans = '0' + ans;
                }else{
                    ans = '1' + ans;
                }
            }else{
                if(carry){
                    ans = '1' + ans;
                }else{
                    ans = '0' + ans;
                    carry = true;
                }
            }
        }
        for(int i = l.length()-s.length()-1; i >= 0; i--){
            char bit = l[i];
            if(bit == '0'){
                if(carry){
                    ans = '1' + ans;
                    carry = false;
                }else{
                    ans = '0' + ans;
                }
            }else{
                if(carry){
                    ans = '0' + ans;
                }else{
                    ans = '1' + ans;
                }
            }
        }
        return carry ? '1' + ans : ans;
    }
};