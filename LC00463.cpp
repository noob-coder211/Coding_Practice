class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                    continue;
                else
                {
                    if(i>0)
                        ans = ans + 1 - grid[i-1][j];
                    else
                        ans++;
                    if(j>0)
                        ans = ans + 1 - grid[i][j-1];
                    else
                        ans++;
                    if(i<n-1)
                        ans  =  ans + 1 -  grid[i+1][j];
                    else
                        ans++;
                    if(j<m-1)
                        ans = ans + 1 - grid[i][j+1];
                    else
                        ans++;
                }
            }
        }
        return ans;
    }
};