/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> m;
        if(head == NULL)
            return NULL;
        Node * new_head = new Node(head->val);
        Node * cur = new_head;
        Node * temp = head;
        m[head] = new_head;
        while(head->next!=NULL)
        {
            head = head->next;
            int num = head->val;
            Node * new_node = new Node(num);
            cur->next = new_node;
            cur = cur->next;
            m[head] = new_node;
        }
        head = temp;
        cur = new_head;
        while(head!= NULL)
        {
            Node * rand = head->random;
            Node * new_rand = m[rand];
            cur->random = new_rand;
            head = head->next;
            cur = cur->next;
        }
        return new_head;

    }
};