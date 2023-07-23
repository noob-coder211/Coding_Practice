class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[n-1];
        long long cur = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] <= cur)
            {
                cur+= nums[i];
            }
            else
            {
                cur = nums[i];  
            }
            ans = max(ans, cur);
        }
        return ans;
        
        
    }
};