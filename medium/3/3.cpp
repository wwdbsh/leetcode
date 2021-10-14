#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> slideIndex;
        int start = 0, len = 0;
        for(int i = 0; i < s.length(); i++){
            if(slideIndex.count(s[i]) > 0 && start <= slideIndex[s[i]]){
                start = slideIndex[s[i]] + 1;
            }
            slideIndex[s[i]] = i;
            len = max(len, i-start+1);
        }
        return len;
    }
};
