class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {

        int t=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j] == 0)
                    t++;
            }
        }
        int ans = INT_MAX;
        if(t == 0)
            return 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j] == 0)
                {
                    for(int k = 0;k<3;k++)
                    {
                        for(int l = 0;l<3;l++)
                        {
                            if(grid[k][l] > 1)
                            {
                                int d = abs(i-k) + abs(j-l);
                                grid[k][l]--;
                                grid[i][j] = 1;
                                ans = min(ans, d+ minimumMoves(grid));
                                grid[k][l]++;
                                grid[i][j] = 0;
                            }
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};