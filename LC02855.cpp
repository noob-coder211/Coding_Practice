class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int smallest = 101;
        int index = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]< smallest)
            {
                smallest = nums[i];
                index = i;
            }
        }
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for(int i=0;i<n;i++)
        {
            if(temp[i] != nums[(index+i)%n])
                return -1;
        }
        return (n-index)%n;
        
    }
};