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
struct Result {
    bool ans;
    ListNode *retnode;
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        int length = 0;
        ListNode *cur = head;
        while(cur != nullptr) {
            length++; 
            cur = cur->next;
        }
        Result *res = isPalindromeUtil(head, length);
        return res->ans;
    }
    
    Result* isPalindromeUtil(ListNode *node, int length) {
        if(length == 1) {
            Result *x = new Result();
            x->ans = true;
            x->retnode = node->next;
            return x;
        } 
        if(length == 0) {
            Result *x = new Result(); x->ans = true; x->retnode = node;
            return x;
        }
        Result *r = isPalindromeUtil(node->next, length-2);
        if(r->ans == false) return r;
        if(r->retnode->val != node->val) {
            r->ans = false;
            return r;
        }
        r->retnode = r->retnode->next;
        r->ans = true;
        return r;
    }
};
