/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MIN;
        int current_sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        int max_lvl = 1;
        TreeNode * placeholder = new TreeNode (INT_MIN);
        q.push(placeholder);
        while(q.size()>0)
        {
            TreeNode * n = q.front();
            q.pop();
            if(n == NULL)
                continue;
            else if(n->val == INT_MIN)
            {
                if(current_sum > ans)
                    max_lvl = level;
                ans = max(ans, current_sum);
                current_sum = 0;
                level++;
                //cout<<q.size()<<" "<<level<<endl;
                if(q.size() > 0)
                    q.push(placeholder);  
            }
            else
            {
                current_sum+= n->val;
                if(n->left != NULL)
                    q.push(n->left);
                if(n->right != NULL)
                    q.push(n->right);
            }
        }
        return max_lvl;
        
        
    }
};