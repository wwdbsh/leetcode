#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        string l, s;
        if(num1.length() > num2.length()){
            l = num1;
            s = num2;
        }else{
            l = num2;
            s = num1;
        }
        
        vector<string> v;
        int carry = 0;
        for(int i = s.length()-1; i >= 0; i--){
            string n = "";
            for(int j = l.length()-1; j >= 0; j--){
                int cal = (int)(s[i]-'0')*(int)(l[j]-'0')+carry;
                int remainder = cal%10;
                carry = cal/10;
                n = (char)(remainder+'0') + n;
            }
            if(carry != 0){
                n = (char)(carry+'0') + n;
            }
            v.push_back(n);
            carry = 0;
        }
        
        string ans = v[0];
        for(int i = 1; i < v.size(); i++){
            for(int j = 0; j < i; j++){
                v[i] = v[i] + '0';
            }
            ans = add(ans, v[i]);
        }
        return ans;
    }
private:
    string add(string num1, string num2){
        string rt = "";
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0, remainder = 0, cal = 0;
        while(i >= 0 || j >= 0){
            if(i >= 0 && j >= 0){
                cal = ((int)(num1[i]-'0')+(int)(num2[j]-'0'))+carry;
            }else if(i >= 0 && j < 0){
                cal = (int)(num1[i]-'0')+carry;
            }else if(j >= 0 && i < 0){
                cal = (int)(num2[j]-'0')+carry;
            }
            carry = (int)(cal/10);
            remainder = cal%10;
            rt = (char)(remainder+'0') + rt;
            i--; j--;
        }
        if(carry != 0){
            rt = (char)(carry+'0') + rt;
        }
        return rt;
    }
};