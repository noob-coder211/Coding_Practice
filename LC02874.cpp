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
        vector<int> left_max(n, 0);
        max_val = nums[0];
        for(int i=1;i<n;i++)
        {
            left_max[i] = max(left_max[i], max_val);
            max_val = max(max_val, nums[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            long long val = left_max[i] - nums[i];
            if(val>0)
            {
                val = val * max_nums[i];
                ans = max(ans, val);
            }
        }
        return ans;
        
    }
};