#include<iostream>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if((s.length() == 0 && t.length() == 1) || (t.length() == 0 && s.length() == 1)){
            return true;
        }
        if(s == t){
            return false;
        }
        if(s.length()-t.length() == 0){
            for(int i = 0; i < s.length(); i++){
                if(s[i] != t[i]){
                    s[i] = t[i];
                    break;
                }
            }
            return s == t;
        }else if(s.length()-t.length() == 1){
            string temp = "";
            int i = 0;
            while(i < s.length()){
                if(s[i] != t[i]){
                    i++;
                    break;
                }
                temp += s[i];
                i++;
            }
            while(i < s.length()){
                temp += s[i];
                i++;
            }
            return temp == t;
        }else if(s.length()-t.length() == -1){
            string temp = "";
            int i = 0;
            bool flag = false;
            while(i < s.length()){
                if(s[i] != t[i]){
                    temp += t[i];
                    flag = true;
                    break;
                }
                temp += s[i];
                i++;
            }
            if(flag){
                while(i < s.length()){
                    temp += s[i];
                    i++;
                }
            }else{
                while(i < t.length()){
                    temp += t[i];
                    i++;
                }
            }
            return temp == t;
        }else{
            return false;
        }
    }
};