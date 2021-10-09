#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> table;
        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums[i];
            if(table.count(temp) > 0){
                return {table[temp], i};
            }
            table[nums[i]] = i;
        }
        return {};
    }
};