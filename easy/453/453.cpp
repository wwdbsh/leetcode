#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = nums.size()-1; i > 0; i--){
            cnt += nums[i] - nums[0];
        }
        return cnt;
    }
};