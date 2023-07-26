class Solution {
public:

    long long int getspeed(long long int lo, long long int hi, vector<int> dist, double hour)
    {
        long long int mid = (lo+hi)/2;

        while(lo < hi)
        {
            double time = 0.0;
            for(int i=0;i<dist.size()-1;i++)
            {
                time+= ceil((float)dist[i]/ mid);
            }
            int n = dist.size();
            time+= (float) dist[n-1]/mid;
            cout<<time<<endl;
            cout<<mid<<endl;

            if(time == hour)
                return mid;

            if(time > hour)
                lo = mid+1;
            else
                hi = mid;
            mid = (lo+hi)/2;
        }
        return mid;
    }


    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long int lo =1;
        long long int n = dist.size();
        long long int sum = 0;
        for(int i :dist)
            sum+=i;
        long long int hi = sum;
        if(hour <= n-1)
            return -1;
        return (int)getspeed(lo, 10000000, dist, hour);
    }
};