class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int last = -1;
        int n = nums.size();
        int ans = 0;
        int cur = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 1)
                {cur++;
                ans = max(ans, cur);
                continue;}
            else
            {
                if(last == -1)
                {
                    last = i;
                }
                else
                {
                    cur = i-last-1;
                    last = i;
                    //cout<<last<<endl;
                    //cout<<cur<<endl;
                }
                ans = max(ans, cur);
            }
        }
        ans = max(ans, cur);
        if(last == -1)
            return ans-1;
        return ans;
        
    }
};