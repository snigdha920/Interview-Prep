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
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *reverseHead = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr, *cur = reverseHead;
        while(cur) {
            reverseHead = cur;
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        // while(p1 != nullptr) {cout << p1->val << " "; p1=p1->next;}
        // cout << endl;
        ListNode *p1 = head, *p2 = reverseHead;
        bool res = 1;
        while(p1 && p2) {
            if(p1->val != p2->val) {
                res = 0;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return res;
    }
};
