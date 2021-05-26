#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> v;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count++;
            }else{
                v.push_back(nums[i]);
            }
        }
        while(count-- > 0){
            v.push_back(0);
        }
        nums = v;
    }
};