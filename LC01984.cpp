class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        int i = 0;
        int  j = k-1;

        while(j<nums.size())
        {
            ans = min(ans, nums[j] - nums[i]);
            j++;
            i++;
        }
        return ans;
    }
};