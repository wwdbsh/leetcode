#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1);
        int idx1 = 0, idx2 = 0;
        for(int i = 0; i < nums1.size(); i++){
            if(idx1 >= m){
                nums1[i] = nums2[idx2++];
            }else if(idx2 >= n){
                nums1[i] = temp[idx1++];
            }else{
                nums1[i] = temp[idx1] <= nums2[idx2] ? temp[idx1++] : nums2[idx2++];
            }
        }
    }
};