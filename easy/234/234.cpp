#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        for(ListNode* cur = head; cur != nullptr; cur=cur->next){
            arr.push_back(cur->val);
        }
        for(int left = 0, right = arr.size()-1; left <= right; left++, right--){
            if(arr[left] != arr[right]){
                return false;
            }
        }
        return true;
    }
};