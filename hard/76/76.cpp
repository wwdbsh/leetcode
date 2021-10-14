#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charCount (128, 0);
        for (char c : t) charCount[c]++;
        int left = 0, cnt = 0, minLen = s.length() + 1;
        string res("");
        for (int right = 0; right < s.length(); right++) {
            if (--charCount[s[right]] >= 0)
                cnt++;
            while (left <= right && cnt == t.length()) {
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    res = s.substr(left, minLen);
                }
                if (++charCount[s[left++]] > 0)
                    cnt--;
            }
        }
        return res;
    }
};
