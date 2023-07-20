class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int l=0;
        int r = n;
        if(target < nums[0])
            return 0;
        
        while(l+1<=r)
        {
            int mid = (l+r)/2;
            //cout<<mid<<endl;
            //cout<<nums[mid]<<endl;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid;
        }
        return r;      
    }
};