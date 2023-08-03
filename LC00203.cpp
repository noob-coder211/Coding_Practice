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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode * newhead = new ListNode(0);
        newhead->next = head;

        ListNode * prev = newhead;
        ListNode * cur = head;

        while(cur!=NULL)
        {
            if(cur->val == val)
            {
                prev->next = cur->next;
                cur = prev->next;
            }
            else
            {
                prev = prev->next;
                cur = cur->next;
            }
        }
        return newhead->next;
        
    }
};