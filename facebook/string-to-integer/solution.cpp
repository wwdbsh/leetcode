#include <iostream>
#include <sstream>
#define LOWER -2147483648
#define UPPER 2147483647

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        unsigned int temp = 0;
        s = removeLeadingWhiteSpace(s);
        bool negative = isNegative(s);
        if(s[0] == '-' || s[0] == '+'){
            s = s.substr(1, s.length()-1);
        }
        s = getNumPart(s);
        stringstream ss(s);
        ss >> temp;
        int ans = 0;
        if(negative){
            if(temp > UPPER){
                ans = LOWER;
            }else{
                ans = temp*-1;
            }
        }else{
            if(temp > UPPER){
                ans = UPPER;
            }else{
                ans = temp;
            }
        }
        return ans;
    }

private:
    string removeLeadingWhiteSpace(string s){
        int bound = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                bound = i;
                break;
            }
        }
        return s.substr(bound, s.length()-bound);
    }
    bool isNegative(string s){
        return s[0] == '-';
    }
    string getNumPart(string s){
        string rt = "";
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c >= 48 && c <= 57){
                rt += c;
            }else{
                break;
            }
        }
        return rt;
    }
};

int main(void){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.myAtoi(s) << "\n";
}