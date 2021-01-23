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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *prev, *x = head, *y = head->next;
        prev = nullptr;
        head = nullptr;
        while(x != nullptr && y != nullptr) {
            if(x->val != y->val) {
                if(prev == nullptr) {
                    prev = x;
                    head = x;
                } else {
                    prev->next = x;
                    prev = prev->next;
                }
                x = x->next;
                y = y->next;
                continue;
            }
            while(y != nullptr && x->val == y->val) {
                ListNode *temp = y;
                y = y->next;
                delete temp;
            }
            x = y;
            if(x != nullptr) y = x->next;
        }
        if(prev == nullptr) {
            prev = x;
            head = x;
        } else {
            prev->next = x;
            prev = prev->next;
        }
        return head;
    }
};
