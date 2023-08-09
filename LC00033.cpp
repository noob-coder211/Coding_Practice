class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int l = 0;
        int r = n-1;

        if(n == 1)
        {
            if(nums[0] == target)
                return 0;
            return -1;
        }

        while(l<=r)
        {
            cout<<l<<" "<<r<<endl;
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] >= nums[l])
            {
                if(nums[l] <= target && nums[mid] > target)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(nums[mid] < target && nums[r] >= target)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid - 1;
                }
            }

        }
        return -1;
    }
};