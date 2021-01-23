/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Using Floyd Warshall Algorithm
        if(head == nullptr || head->next == nullptr) {
            return false;
        }
        bool res = false;
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                res = true;
                break;
            }
        }
        return res;
    }
};
