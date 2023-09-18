
using ll = long long;
class Solution {
public:

    bool binary_search(int budget, vector<vector<int>> &composition, vector<int>& stock, vector<int>& cost, ll mid)
    {
        ll mincost = INT_MAX;
        for(int i=0;i<composition.size();i++)
        {
            ll curcost = 0;
            for(int j=0;j<composition[i].size();j++)
            {
                ll curr = composition[i][j] * mid;
                if(stock[j] >= curr)
                    continue;
                else
                {
                    ll extra = (curr - stock[j]) * cost[j];
                    curcost+= extra;
                }
            }
            mincost = min(mincost, curcost);
        }
        return mincost<=budget;

    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {

        ll hi = 1e9;
        int ans = 0;
        ll lo = 0;
        while(lo<=hi)
        {
            ll mid = lo + (hi-lo)/2;
            if(binary_search(budget, composition, stock, cost, mid))
            {
                lo = mid+1;
                ans = mid;
            }
            else
                hi = mid-1;
        }
        return ans;  
    }
};