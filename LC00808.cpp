class Solution {
public:
    vector<vector<double>> dp;
    double getprob(int i, int j)
    {
        return 0.25*(dp[max(0, i-4)][j] + dp[max(0,i-3)][j-1] + dp[max(0, i-2)][max(0, j-2)] + dp[i-1][max(0, j-3)]);
    }

    double soupServings(int n) {

        dp.clear();

        
        int m = ceil(n/25.0);
        if(m>500)
            return 1.0;
        dp.resize(m+1, vector<double>(m+1, 0.0));
        //vector<vector<double>> dp(m+1, vector<double>(m+1, 0.0));



        dp[0][0] = 0.5;
        for(int i=1;i<=m;i++)
        {
            dp[0][i] = 1;
        }
        for(int i=1;i<=m;i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 1;

            for(int j=1;j<=m;j++)
            {
                dp[i][j] = getprob( i, j);
            }
            if(dp[i][i] > 1- 1e-5)
                return 1;            
        }
        return dp[m][m];
        
    }
};