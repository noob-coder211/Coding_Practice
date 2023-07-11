class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {

/*
        int n = nums.size();

        for(int i=0;i<n-k;i++)
        {
            int val = nums[i];
            nums[i] = 0;
            if(val!= 0){
            for(int j=i+1;j<i+k;j++)
            {
                nums[j] = nums[j] - val;
                if(nums[j]<0)
                    return false;
            }
            }
        }
        for(int i=0;i<n;i++)
        {
            if (nums[i] >0)
                return false;
        }
        return true;
 */

    int cur = 0;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        if(cur > nums[i])
            return false;
        nums[i] = nums[i] - cur;
        cur = cur + nums[i];

        if(i>= k-1)
            cur = cur-nums[i-k+1];
    }
    return cur == 0;    

    }
};