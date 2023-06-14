class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums)
        {
            set.insert(num);
        }
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0){
            if(set.count(-1*nums[i]) != 0)
                ans = max(ans, nums[i]);}
        }
        return ans;
        
    }
};