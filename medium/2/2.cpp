#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val+l2->val;
        int carry = 0;
        if(sum > 9){
            carry = 1;
            sum -= 10;
        }
        ListNode* rt = new ListNode(sum);
        ListNode* head = rt;
        ListNode* l1_cur = l1->next;
        ListNode* l2_cur = l2->next;
        while(l1_cur != nullptr && l2_cur != nullptr){
            sum = l1_cur->val + l2_cur->val + carry;
            if(sum > 9){
                carry = 1;
                sum -= 10;
            }else{
                carry = 0;
            }
            l1_cur = l1_cur->next;
            l2_cur = l2_cur->next;
            ListNode * new_node = new ListNode(sum);
            rt->next = new_node;
            rt = rt->next;
        }
        if(l1_cur == nullptr){
            while(l2_cur != nullptr){
                sum = l2_cur->val+carry;
                if(sum > 9){
                    carry = 1;
                    sum -= 10;
                }else{
                    carry = 0;
                }
                ListNode * new_node = new ListNode(sum);
                l2_cur = l2_cur->next;
                rt->next = new_node;
                rt = rt->next;
            }
        }else{
            while(l1_cur != nullptr){
                sum = l1_cur->val+carry;
                if(sum > 9){
                    carry = 1;
                    sum -= 10;
                }else{
                    carry = 0;
                }
                ListNode * new_node = new ListNode(sum);
                l1_cur = l1_cur->next;
                rt->next = new_node;
                rt = rt->next;
            }
        }
        if(carry == 1){
            ListNode * new_node = new ListNode(1);
            rt->next = new_node;
        }
        return head;
    }
};