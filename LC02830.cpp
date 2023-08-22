class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        //int n = offers.size();
        int dp[100002] = {};
        unordered_map<int, vector<pair<int, int>>> m;
        for(auto offer: offers)
        {
            m[offer[1]].push_back({offer[0], offer[2]});
        }
        for(int end=0;end<n;end++)
        {
            dp[end+1] = dp[end];
            if(m.count(end))
            {
                for(auto [start, gold]: m[end])
                {
                    dp[end+1] = max(dp[end+1], dp[start] + gold);
                }
            }
        }
        return dp[n];
        
        
    }
};