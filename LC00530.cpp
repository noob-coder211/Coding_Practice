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

    void get_inorder(vector<int> & vec, TreeNode * root)
    {
        if(root == NULL)
            return;
        if(root->left)
            get_inorder(vec, root->left);
        vec.push_back(root->val);
        if(root->right)
            get_inorder(vec, root->right);
    }


    int getMinimumDifference(TreeNode* root) {
        int ans = 100000;
        vector<int> nodes ;
        get_inorder(nodes, root);
        cout<<nodes.size()<<endl;
        for(int i=1;i<nodes.size();i++)
        {
            ans = min(ans, nodes[i] - nodes[i-1]);
        }
        return ans;
        
    }
};