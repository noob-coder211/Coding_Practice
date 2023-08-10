class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i=1;
    int j=2;
    if(n<3)
        return n;
    while(j<n)
    {
        if(nums[i] == nums[j])
        {
            if(nums[i-1] == nums[j])
                j++;
            else
                {
                    i++;
                    nums[i] = nums[j];
                    j++;
                }
        }
        else
        {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }
    return i+1;
        
    }
};