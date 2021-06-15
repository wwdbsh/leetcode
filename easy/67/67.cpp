#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string long_binary = a; 
        string short_binary = b;
        if(a.length() < b.length()){
            long_binary = b;
            short_binary = a;
        }
        for(int i = 0; i < long_binary.length()-short_binary.length(); i++){
            short_binary = "0" + short_binary;
        }
        string ans;
        bool carry = false;
        for(int index = long_binary.length()-1; index >= 0; index--){
            char bit1 = long_binary[index];
            char bit2 = short_binary[index];
            char bit3 = carry ? '1' : '0';
            if(bit1 == '0' && bit2 == '0'){
                carry = false;    
            }else if(bit1 == '1' && bit2 == '1'){
                if(bit3 == '1'){
                    bit3 = '1';
                }else{
                    bit3 = '0';
                }
                carry = true;
            }else{
                if(bit3 == '1'){
                    bit3 = '0';
                    carry = true;
                }else{
                    bit3 = '1';
                    carry = false;
                }
            }
            ans = bit3 + ans;
        }
        
        return carry ? '1' + ans : ans;
    }
};