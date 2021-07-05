#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int negative_count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                return 0;
            }else if(nums[i] < 0){
                negative_count++;
            }else{
                break;
            }
        }
        return negative_count % 2 == 0 ? 1 : -1;
    }
};