#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        deque<char> dq;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(m[c] > 0){
                ans = max(ans, (int)dq.size());
                while(dq.front() != c){
                    m[dq.front()] = 0;
                    dq.pop_front();
                }
                dq.pop_front();
            }else{
                m[c] = 1;
            }
            dq.push_back(c);
        }
        return max(ans, (int)dq.size());
    }
};

int main(void){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.lengthOfLongestSubstring(s) << "\n";
}