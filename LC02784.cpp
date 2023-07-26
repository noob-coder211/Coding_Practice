class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool flag = false;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] != i+1)
                return false;
        }
        int n = nums.size();
        return nums[n-1] == n-1;
        
    }
};