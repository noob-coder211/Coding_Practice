class Solution {
public:
    long long minimumCost(string s) {
        
        int n = s.size();
        
        int middle = n/2;
        
        long long int cost=  0;
        
        for(int i=middle-1;i>=0;i--)
        {
            if(s[i] != s[i+1])
                cost = cost + i+ 1;
        }
        
        for(int i=middle+1; i<n;i++)
        {
            if(s[i-1] != s[i])
                cost = cost + n - i;
        }
        return cost;
    }
};