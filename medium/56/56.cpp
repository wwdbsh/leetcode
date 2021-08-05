#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int s = intervals[0][0], e = intervals[0][1];
        for(int index = 1; index < intervals.size(); index++){
            if(intervals[index][0] <= e){
                if(intervals[index][1] > e){
                    e = intervals[index][1];
                }
            }else{
                ans.push_back({s, e});
                s = intervals[index][0];
                e = intervals[index][1];
            }
        }
        if(ans.size() == 0 || (ans[ans.size()-1][0] != s && ans[ans.size()-1][1] != e)){
            ans.push_back({s, e});
        }
        return ans;
    }
};