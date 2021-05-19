#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[30000];

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            max_sum = max(max_sum, dp[i]);
        }
        return max_sum;
    }
};