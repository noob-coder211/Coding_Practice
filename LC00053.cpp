class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int cur = 0;

        for(int i=0;i<nums.size();i++)
        {
            cur += nums[i];
            if(cur<0 )
                cur = 0;
            else
            {
                ans = max(ans, cur);
            }
        }
        if(ans<=0)
            return * max_element(nums.begin(), nums.end());
        else
            return ans;


        
    }
};