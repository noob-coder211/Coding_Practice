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
    vector<TreeNode*> allPossibleFBT(int n) {

        vector<vector<TreeNode *>> dp(n+1);
        vector<TreeNode *> ans;
        if(n%2 == 0)
            return ans;
        TreeNode*  root = new TreeNode(0);
        dp[1].push_back(root);

        for(int count = 3; count<n+1;count+=2)
        {
            for(int i = 1;i<count-1;i++)
            {
                int left = i;
                int right = count - i - 1;

                vector<TreeNode*> leftnode = dp[left];
                vector<TreeNode*> rightnode = dp[right];

                for(auto lnode: leftnode)
                {
                    for(auto rnode: rightnode)
                    {
                        TreeNode * newnode = new TreeNode(0, lnode, rnode);

                        dp[count].push_back(newnode);

                    }
                }

                
            }
        }
        return dp[n];
        
    }
};