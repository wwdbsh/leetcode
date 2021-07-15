#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,bool> table;
        for(int i = 0; i < nums1.size(); i++){
            if(table.count(nums1[i]) == 0){
                table[nums1[i]] = true;
            }
        }
        vector<int> ans;
        for(int i = 0; i < nums2.size(); i++){
            if(table.count(nums2[i]) > 0 && table[nums2[i]]){
                table[nums2[i]] = false;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};