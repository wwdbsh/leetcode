#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        for(int i = strs[0].length(); i >= 1; i--){
            string prefix = strs[0].substr(0, i);
            for(int j = 0; j < strs.size(); j++){
                if(prefix != strs[j].substr(0, i)){
                    break;
                }
                if(j == strs.size()-1){
                    return prefix;
                }
            }
        }
        return "";
    }
};