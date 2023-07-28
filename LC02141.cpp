class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        sort(batteries.begin(), batteries.end());

        long long int extra = 0;
        reverse(batteries.begin(), batteries.end());
        int m = batteries.size();
        for(int i=n;i<m;i++)
        {
            extra+= batteries[i];
        }
        //cout<<extra<<endl;
        for(int i=n-1;i>0;i--)
        {
            if(extra >= (n-i) * (batteries[i-1] - batteries[i]))
            {
                extra = extra -  (n-i) * (batteries[i-1] - batteries[i]);
            }
            else
            {
                return batteries[i] + extra/(long)(n-i);
            }
        }
        return batteries[0] + extra/(long) n;
        
    }
};