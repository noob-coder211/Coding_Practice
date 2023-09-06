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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans;

        int n = 0;
        ListNode * temp = head;
        while(temp!= NULL)
        {
            n++;
            temp = temp->next;
        }
        int div = n / k;
        int rem = n% k ;
        temp = head;
        int splits = 0;
        while(temp!= NULL)
        {
            ListNode * newhead = new ListNode (temp->val);
            ListNode * newtemp = newhead;
            for(int i=1;i<div;i++)
            {
                temp = temp->next;
                if(temp == NULL)
                    break;
                newtemp->next = new ListNode(temp->val);
                newtemp = newtemp->next;
            }
            if(div != 0 && splits < rem)
            {
                temp = temp->next;
                if(temp == NULL)
                    break;
                newtemp->next = new ListNode(temp->val);
                newtemp = newtemp->next;
                splits++;
            }
            temp = temp->next;
            ans.push_back(newhead);   
        }
        while(ans.size() < k)
        {
            ListNode * null = new ListNode();
            ans.push_back(nullptr);
        }
        return ans;
        
    }
};