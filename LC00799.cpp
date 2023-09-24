class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> glass(102, vector<double> (102,0));
        glass[0][0] = poured;
        for(int i=0;i<=query_row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                double flow = (glass[i][j] - 1.0)/2.0;
                if(flow > 0)
                {
                    glass[i+1][j] += flow;
                    glass[i+1][j+1]+= flow;
                }
            }
        }
        return min(1.0, glass[query_row][query_glass]);
        
    }
};