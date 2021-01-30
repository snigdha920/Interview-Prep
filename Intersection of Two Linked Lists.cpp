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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        ListNode *ans = nullptr, *p1 = headA, *p2 = headB;
        for(int i=0; i<=(l1+l2) && p1 && p2; i++) {
            if(p1 == p2) {
                ans = p2;
                break;
            } 
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == nullptr) p1 = headB;
            if(p2 == nullptr) p2 = headA;
        }
        return ans;
    }
    int length(ListNode *head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }
};
