#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, index = 0;
        map<int,bool> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.count(nums[i]) == 0){
                m[nums[i]] = true;
                nums[index++] = nums[i];
                k++;
            }
        }
        return k;
    }
};