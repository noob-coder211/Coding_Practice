class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int cursum = 0;
        int ans = INT_MAX;


        for(right = 0;right<n;right++)
        {
            cursum += nums[right];
            //cout<<cursum<<" "<<right<<endl;

            while(cursum>= target)
            {
                cout<<left<<" "<<right<<endl;
                cursum-=nums[left];
                left++;
                ans = min(ans, right-left+2);
                //cout<<cursum<<" "<<left<<endl;
            }
        }
        //cout<<ans<<endl;
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};