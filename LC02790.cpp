class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        long long int t = 0;
        long long int count = 0;
        for(int val: usageLimits)
        {
            t+= val;

            if(t>= ((count+1) * (count+2))/2)
                count+=1;
        }
        return count;
        
    }
};