class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int onecount = 0;
        int twocount = 0;
        int zerocount = 0;

        for(int num:  nums)
        {
            if(num == 0)
                zerocount++;
            if(num == 1)
                onecount++;
            if(num == 2)
                twocount++;
        }
        int i = 0;
        while(zerocount>0)
        {
            nums[i] = 0;
            zerocount--;
            i++;
        }
        while(onecount>0)
        {
            nums[i] = 1;
            onecount--;
            i++;
        }
        while(twocount>0)
        {
            nums[i] = 2;
            twocount--;
            i++;
        }
        
    }
};