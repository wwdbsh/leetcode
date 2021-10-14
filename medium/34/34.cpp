#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        bSearch(ans, nums, 0, nums.size()-1, target);
        if(ans.size() == 0) ans = {-1, -1};
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    void bSearch(vector<int>& ans, vector<int>& nums, int start, int end, int target){
        if(start > end){
            return;
        };
        
        int mid = (start + end) / 2;
        
        if(nums[mid] == target){
            if(mid == 0 || (mid > 0 && nums[mid-1] != target)){
                ans.push_back(mid);
            }
            if(mid == nums.size()-1 || (mid < nums.size()-1 && nums[mid+1] != target)){
                ans.push_back(mid);
            }
            bSearch(ans, nums, start, mid-1, target);
            bSearch(ans, nums, mid+1, end, target);
        }else if(nums[mid] > target){
            bSearch(ans, nums, start, mid-1, target);
        }else{
            bSearch(ans, nums, mid+1, end, target);
        }
    }
};