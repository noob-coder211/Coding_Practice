class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int flag = 0;
        int n = nums.size();
        int cur = 0;
        int start = 0;
        for(int i=0;i<n;i++)
        {
            if(start == 1){
                if(flag == 0)
                {
                    if(nums[i] %2 == 0 && nums[i] <= threshold)
                    {
                        cur++;
                        ans = max(ans, cur);
                        flag = 1;
                    }
                    else
                    {
                        cur = 0;
                        start = 0;
                    }
                }
                else
                {
                    if(nums[i] %2 == 1 && nums[i] <= threshold)
                    {
                        cur++;
                        ans = max(ans, cur);
                        flag = 0;
                    }
                    else if(nums[i] <= threshold)
                    {
                        cur = 1;
                        flag = 1;
                        start = 1;
                    }
                    else
                    {
                        cur = 0;
                        flag = 0;
                        start = 0;
                    }

                }
            }
            else
            {
                if(flag == 0)
                {
                    if(nums[i] %2 == 0 && nums[i] <= threshold)
                    {
                        cur++;
                        ans = max(ans, cur);
                        flag = 1;
                        start = 1;
                    }
                    else
                    {
                        cur = 0;
                        start = 0;
                    }
                }
                
            }
            
            
        }
        return ans;
        
    }
};