#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(temp);
        }
        vector<vector<string>> v;
        for(auto e : m){
            v.push_back(e.second);
        }
        return v;
    }
};