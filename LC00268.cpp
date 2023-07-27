class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int ans = nums[0];
        for(int i = 1;i<n;i++)
        {
            ans= ans^ nums[i];
            ans = ans^i;
            //index++;
        }
        ans = ans^n;
        return ans;
        
    }
};