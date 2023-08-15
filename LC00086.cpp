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

        ListNode * left = new ListNode(-200);
        ListNode * right = new ListNode(-200);
        ListNode * ans = left;
        ListNode * righthead = right;

        while(head!= NULL)
        {
            if(head->val<x)
            {
                ListNode * newleft = new ListNode(head->val);
                left->next = newleft;
                left = left->next;
            }
            else{
                ListNode * newright = new ListNode(head->val);
                right->next = newright;
                right = right->next;
            }
            head = head->next;
        }
        left->next = righthead->next;
        return ans->next;
        
    }
};