#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(1);
        for(int i = 1; i < nums.size(); i++){
            ans.push_back(ans[i-1]*nums[i-1]);
        }
        int r = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            ans[i] *= r;
            r *= nums[i];
        }
        return ans;
    }
};