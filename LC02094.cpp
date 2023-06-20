class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long int n = nums.size();
        vector<long long int> v(n, 0);
        v[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            v[i] = v[i-1] + (long long int)nums[i];
        }
        vector<int> ans(n, -1);
        for(long long int i=0;i<n;i++)
        {
            if(i-k<0 || i+(long long int)k >= n || i+k <0)
                continue;
            else
            {
                long long int sum = v[i+k] - v[i-k];
                sum+= nums[i-k];
                int avg = sum / (2*k + 1);
                ans[i] = avg;
            }
        }
        return ans;
        
    }
};