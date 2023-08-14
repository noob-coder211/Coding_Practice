class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int ans = 0;
        int n = nums.size();
        if(n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int cur = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                cur++;
            }
            else if(nums[i] == nums[i-1])
                continue;
            else
                cur = 0;
            ans = max(ans, cur);
        }
        return ans+1;
        
    }
};