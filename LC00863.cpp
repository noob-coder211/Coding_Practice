/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool getpath(TreeNode * root, TreeNode * target, vector<TreeNode *>& path)
{
    if(root == NULL)
        return false;
    
    path.push_back(root);
    //cout<<root->val<<" "<<path.size()<<endl;
    if(root == target)
        return true;

    if (getpath(root->left, target, path) || getpath(root->right, target, path))
        return true;
    path.pop_back();
    return false;
}

vector<TreeNode *> finalpath(TreeNode * root, TreeNode * target)
{
    vector<TreeNode*> p;
    getpath(root, target, p);
    return p; 
}

void findnodes(TreeNode * root, int k, vector<int> & nodes)
{
    if(root == NULL)
        return;

    if(k == 0)
        {nodes.push_back(root->val);
        return;}
    
    k--;
    findnodes(root->left, k , nodes);
    findnodes(root->right, k, nodes);
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        vector<TreeNode *> path;
        path = finalpath(root, target);

        //cout<<path.size()<<endl;
        //cout<<path[0]->val<<endl;
        findnodes(target, k, ans);
        k--;
        for(int i= path.size()-1; i>0;i--)
        {
            if(k == 0)
            {
                ans.push_back(path[i-1]->val);
                return ans;
            }
            TreeNode * prevnode = path[i-1]->left == path[i] ? path[i-1]->right: path[i-1]->left;
            //cout<<"here"<<endl;
            findnodes(prevnode, k-1, ans);
            k--;
            //cout<<k<<endl;
        }
        return ans;
        
    }
};