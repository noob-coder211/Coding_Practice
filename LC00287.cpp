class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        long long int  sum = 0;
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]<=mid)
                    cnt++;
            }
            if(cnt<=mid)
                lo = mid+1;
            else
                hi = mid;
        }
        return hi;
        
    }
};