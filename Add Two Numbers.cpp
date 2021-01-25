/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *cur1 = l1, *cur2 = l2, *tail1, *tail2;
        int digit=0, carry = 0, sum=0;
        while(cur1 && cur2) {
            sum = cur1->val + cur2->val + carry;
            digit = sum%10;
            carry = sum/10;
            cur1->val = digit;
            cur2->val = digit;
            tail1 = cur1; tail2 = cur2;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        bool ret=0;
        while(cur1 && carry) {
            tail1 = cur1;
            sum = carry + cur1->val;
            digit = sum%10;
            carry = sum/10;
            cur1->val = digit;
            cur1 = cur1->next;
        }
        while(cur2) {
            tail2 = cur2;
            sum = carry + cur2->val;
            digit = sum%10;
            carry = sum/10;
            cur2->val = digit;
            cur2 = cur2->next;
            ret = 1;
        }
        if(carry) {
            ListNode *node = new ListNode(carry);
            tail1->next = node;
            tail2->next = node;
        }
        return ret ? l2 : l1;
    }
};
