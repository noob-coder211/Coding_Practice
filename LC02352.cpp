class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int ans = 0;
        int n = grid.size();
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                int flag = 0;
                //cout<< grid[i][j] <<" "<<grid[j][i]<<endl;
                for(int k= 0;k<n;k++)
                {
                    //cout<< grid[i][k] <<" "<<grid[k][j]<<endl;
                    if(grid[i][k] != grid[k][j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                    ans++;
               
            }
            
        }
        return ans;
        
    }
};