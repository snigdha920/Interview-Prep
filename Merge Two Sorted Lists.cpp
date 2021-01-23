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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *start = nullptr, *a = l1, *b = l2;
        if(a->val > b->val) {
            start = b;
            b = b->next;
        } else {
            start = a;
            a = a->next;
        }
        ListNode *res = start;
        while(a != nullptr && b != nullptr) {
            if(a->val > b->val) {
                res->next = b;
                b = b->next;
            } else {
                res->next = a;
                a = a->next;
            }
            res = res->next;
        }
        while(a != nullptr) {
            res->next = a;
            a = a->next;
            res = res->next;
        }
        while(b != nullptr) {
            res->next = b;
            b = b->next;
            res = res->next;
        }
        return start;
    }
};
