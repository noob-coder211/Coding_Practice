class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> m;
        int n = cards.size();
        int ans = n;
        for(int i=0;i<n;i++)
        {
         if(m.count(cards[i]))
         {
             ans = min(ans, i - m[cards[i]]);
             m[cards[i]] = i;
         }
        else
        {
            m[cards[i]] = i;
        }
        }
        if(ans == n)
            return -1;
        return ans+1;
        
    }
};