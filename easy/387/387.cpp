#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        map<char,pair<int, int>> table;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(table.count(c) > 0){
                table[c] = make_pair(table[c].first+1, table[c].second);
            }else{
                table[c] = make_pair(1, i);
            }
        }
        for(map<char,pair<int, int>>::iterator it = table.begin(); it != table.end(); it++){
            if(it->second.first == 1){
                if(ans == -1){
                    ans = it->second.second;
                }else{
                    ans = min(ans, it->second.second);
                }
            }
        }
        return ans;
    }
};