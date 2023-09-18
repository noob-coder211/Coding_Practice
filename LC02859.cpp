class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int set_bits = 0;
            int check = i;
            while(check>0)
            {
                set_bits += check%2;
                check = check/2;
            }
            if(set_bits == k)
                ans+=  nums[i];
        }
        return ans;
        
    }
};