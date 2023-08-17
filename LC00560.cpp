class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = 1;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            //cout<<k-sum<<endl;
            if(m.count(sum - k) != 0)
            {
                ans+= m[sum - k];
            }
            if(m.count(sum) == 0)
                m[sum] = 1;
            else
                m[sum] = m[sum]+1;

        }
        return ans;
        
    }
};