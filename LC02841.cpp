class Solution {
public:
    long long maxSum(vector<int>& nums, int u, int k) {
        
        long long ans = 0;
        
        int n = nums.size();
        unordered_map<int, int> m;
        long long sum = 0;
        for(int i=0;i<k-1;i++)
        {
            sum+= nums[i];
            if(m.count(nums[i]) == 0)
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
        }
        for(int i = k-1;i<n;i++)
        {
            sum+= nums[i];
            if(m.count(nums[i]) == 0)
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
            if(m.size()>=u)
                ans = max(ans, sum);
            sum-= nums[i-k+1];
            m[nums[i-k+1]] --;
            if (m[nums[i-k+1]] == 0)
                m.erase(nums[i-k+1]);
        }
        return ans;
        
    }
};