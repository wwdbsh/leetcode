#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffled_arr;
        for(int i = 0; i < n; i++){
            shuffled_arr.push_back(nums[i]);
            shuffled_arr.push_back(nums[i+n]);
        }
        return shuffled_arr;
    }
};