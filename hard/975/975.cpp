#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        map<int, pair<int,int>> dp;
        
        int nsize = arr.size();
        
        dp[arr[nsize - 1]] = make_pair(1, 1);
        int res = 1;
        
        for (int pos = nsize - 2; pos >=0; --pos) {
            int val = arr[pos];
            auto curval = make_pair(0, 0);
            auto itbound = dp.lower_bound(val);
            if (itbound != dp.end()) {
                curval.first = itbound->second.second;
            }            
			
            if (itbound != dp.end() && itbound->first == val) {
                curval.second = itbound->second.first;
            } else if (itbound != dp.begin()) {
                --itbound;
                curval.second = itbound->second.first;                
            }
			
            res += (curval.first == 1);
            
            dp[val] = curval;
        }
        return res;
    }
};