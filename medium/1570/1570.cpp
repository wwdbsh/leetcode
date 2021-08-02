#include <iostream>
#include <vector>

using namespace std;

class SparseVector {
public:
    vector<int> v;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++){
            v.push_back(nums[i]);
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i]*vec.v[i];
        }
        return sum;
    }
};