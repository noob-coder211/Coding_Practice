class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left_sum;
        int n = nums.size();
        left_sum.push_back(0);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            left_sum.push_back(sum);
        }
        left_sum.pop_back();
        for(int i=0;i<n;i++)
        {
            if(sum - left_sum[i] - nums[i] == left_sum[i])
                return i;
        }
        return -1;
    }
};