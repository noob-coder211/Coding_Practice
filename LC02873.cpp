class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> max_nums(n, 0);
        
        int max_val = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            max_nums[i] = max(max_nums[i], max_val);
            max_val = max(max_val, nums[i]);
            
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long val = nums[i] - nums[j];
                if(val>0)
                {
                    val = val * max_nums[j];
                    ans = max(ans, val);
                }
            }
        }
        return ans;
        
        
    }
};