#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[0], cur = nums[0];
        int max_count = 0, count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == cur){
                count++;
            }else{
                if(max_count < count){
                    max_count = count;
                    ans = cur;
                }
                cur = nums[i];
                count = 1;
            }
        }
        return max_count < count ? cur : ans;
    }
};