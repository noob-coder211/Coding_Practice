class Solution {
public:
    bool canJump(vector<int>& nums) {

       int n = nums.size();
       int i=0;
       for(int reach =0; i<n && i<= reach ; i++)
       {
           reach = max(reach, nums[i] + i);
       }
       return i == n;

    }
};