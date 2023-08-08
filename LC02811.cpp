class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        
        int sum = 0;
        if(n<=2)
            return true;
    
        sum = nums[0]+ nums[1];
        for(int i=2;i<n;i++)
        {
            if(sum>= m)
                return true;
            sum += nums[i];
            sum-= nums[i-2];    
        }
        return sum>=m;
        //return false;

        
        
        
    }
};