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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = new ListNode(-101);
        dummy->next = head;
        ListNode *cur = dummy, *tail = head;
        while(tail->next != nullptr) {
            tail = tail->next;
        }
        ListNode *end = tail;
        while(cur->next != tail) {
            if((cur->next)->val >= x) {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                end->next = temp;
                temp->next = nullptr;
                end = end->next;
            } else {
                cur = cur->next;
            }
        }
        if(tail->val >= x && tail->next != nullptr) {
            ListNode *temp = tail;
            cur->next = cur->next->next; // cur->next = tail->next
            end->next = tail;
            tail->next = nullptr;
        }
        return dummy->next;
    }
};
