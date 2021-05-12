#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(m.count(complement) > 0){
                ans = {i, m[complement]};
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};