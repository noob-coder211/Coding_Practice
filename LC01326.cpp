class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1, 0);
        for(int i=0;i<=n;i++)
        {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ ranges[i]);
            jumps[l] = max(jumps[l], r-l);
        }

        int far = 0;
        int end = 0;
        int count = 0;
        for(int i=0;i<jumps.size()-1;i++)
        {
            if(i>far)
                return -1;
            far = max(far, i+jumps[i]);
            if(i == end)
            {
                count++;
                end = far;
            }
        }
        if(far<n)
            return -1;
        else
            return count;

        
    }
};