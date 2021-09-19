#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int rt = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            switch(c){
                case 'I':
                    if(i+1 < s.length()){
                        if(s[i+1] == 'V'){
                            rt += 4;
                            i++;
                            break;
                        }else if(s[i+1] == 'X'){
                            rt += 9;
                            i++;
                            break;
                        }
                    }
                    rt += 1;
                    break;
                case 'V':
                    rt += 5;
                    break;
                case 'X':
                    if(i+1 < s.length()){
                        if(s[i+1] == 'L'){
                            rt += 40;
                            i++;
                            break;
                        }else if(s[i+1] == 'C'){
                            rt += 90;
                            i++;
                            break;
                        }
                    }
                    rt += 10;
                    break;
                case 'L':
                    rt += 50;
                    break;
                case 'C': //
                    if(i+1 < s.length()){
                        if(s[i+1] == 'D'){
                            rt += 400;
                            i++;
                            break;
                        }else if(s[i+1] == 'M'){
                            rt += 900;
                            i++;
                            break;
                        }
                    }
                    rt += 100;
                    break;
                case 'D':
                    rt += 500;
                    break;
                case 'M':
                    rt += 1000;
            }
        }
        return rt;
    }
};