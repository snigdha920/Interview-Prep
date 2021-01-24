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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode *reverseHead = nullptr, *reverseEnd;
        ListNode *cur = head;
        while(cur != nullptr) {
            ListNode *temp = new ListNode(cur->val);
            temp->next = reverseHead;
            reverseHead = temp;
            cur = cur->next;
        }
        bool res = true;
        ListNode *p1 = head, *p2 = reverseHead;
        while(p1 != nullptr) {
            if(p1->val != p2->val) {
                res = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return res;
    }
};
