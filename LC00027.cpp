class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int new_index = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == val)
                continue;
            nums[new_index++] = nums[i];
            
        }
        return new_index;
    }
};