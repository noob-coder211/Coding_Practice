class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        int n = nums.size();
        int ans = 1e5;
        
        vector<int> dble = nums;
        long long int sum = 0;
        for(int i=0;i<n;i++)
        {
            dble.push_back(nums[i]);
            sum+= nums[i];
        }
        
        int m = dble.size();
        int big_total = 0;
        if(target > sum)
        {
            int rem = target%(sum);
            int quo = (target)/(sum);
            big_total = n*(quo);
            target = rem;
        }
        if(target == 0)
            return big_total;
        
        
        int cur = 0;
        int start = 0;
        long long int total = 0;
        while(cur< m)
        {
            if(total == target)
            {
                ans = min(ans, cur - start);
                total = total - dble[start];
                start++;
            }
            else if(total < target)
            {
                total += dble[cur];
                cur++;
            }
            else if(total > target)
            {
                total = total - dble[start];
                start++;
            }
        }
        if(ans == 1e5)
            return -1;
        return ans+big_total;
        
        
        //return ans;
        
    }
};