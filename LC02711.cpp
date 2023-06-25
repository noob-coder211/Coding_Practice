class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //left
                unordered_set<int> left;
                int k = i-1;
                int l = j-1;
                
                while(k>=0 && l >=0)
                {
                    left.insert(grid[k][l]);
                    k--;
                    l--;
                }
                
                //right
                unordered_set<int> right;
                k = i+1;
                l = j+1;
                while(k<m && l<n)
                {
                    right.insert(grid[k][l]);
                    k++;
                    l++;
                }
                
                if(left.size() > right.size())
                    ans[i][j] = left.size() - right.size();
                else
                    ans[i][j] = right.size() - left.size(); 
            }
        }
        return ans;
        
    }
};