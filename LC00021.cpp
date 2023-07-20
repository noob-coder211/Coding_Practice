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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode * ans = new ListNode(0);
        
        ListNode * final_ans = ans;
        while(list1!=NULL && list2!= NULL)
        {
            
            if(list1->val <= list2->val){
                ans->next = new ListNode(list1->val);
                ans = ans->next;
                list1 = list1->next;}
            else if(list1->val > list2->val){
                ans->next = new ListNode(list2->val);
                ans = ans->next;
                list2 = list2->next;}
        }
        if(list1!=NULL)
            ans->next = list1;
        else if(list2!=NULL)
            ans->next = list2;
        return final_ans->next;
        
    }
};