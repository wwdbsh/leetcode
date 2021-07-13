#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> count_map;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            count_map[nums[i]]++;
            if(cnt < count_map[nums[i]]){
                cnt = count_map[nums[i]];
            }
        }
        int ans = 1e9;
        for(std::map<int,int>::iterator it = count_map.begin(); it != count_map.end(); it++){
            if(cnt == it->second){
                int left = 0, right = nums.size()-1;
                while(nums[left] != it->first) left++;
                while(nums[right] != it->first) right--;
                ans = min(ans, right-left+1);
            }
        }
        return ans;
    }
};