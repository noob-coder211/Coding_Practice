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

    ListNode * reverse(ListNode * head, int n)
    {

        ListNode * prev = NULL;
        ListNode * cur = head;
        ListNode * suc = head->next;
        int count =0 ;
        while(count <= n && cur!=  NULL)
        {
            cur->next = prev;
            prev = cur;
            cur = suc;
            if(cur!= NULL)
                suc = cur->next;
            count++;
        }
        head->next = cur;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode * temphead = new ListNode(0);
        temphead -> next = head;
        int n = 1;
        ListNode * temp = temphead;
        while(n<left)
        {
            temp = temp->next;
            n++;
        }
        cout<<temp->val<<endl;
        temp->next = reverse(temp->next, right-left);
        return temphead->next;

        
    }
};