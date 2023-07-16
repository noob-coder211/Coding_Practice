class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int max_on_right=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans = max(ans, max_on_right - prices[i]);
            max_on_right = max(max_on_right, prices[i]);
        }
        return ans;
        
    }
};