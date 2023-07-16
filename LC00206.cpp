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

/* 
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* suc = head->next->next;
        if(suc == NULL)
            {cur->next = prev;
            cout<<cur->val<<endl;
            return cur;}
        while(cur!=NULL)
        {
            cout<<cur->val<<endl;
            cur->next = prev;
            prev = cur;
            cur = suc;
            if(suc!= NULL)
                {cout<<suc->val<<endl;
                suc = suc->next;}
        }
        cout<<prev->next->val<<endl;
        return prev;

        
    }
*/
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

};