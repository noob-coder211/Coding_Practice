class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {


        /*
        int ans = 0;
        int n = nums.size();
        int i = 0;
        int j = 1;
        int cur_val = nums[0];
        int max_val = 0;
        while(j<n)
        {
            cout<<cur_val<<endl;
            cout<<j<<endl;
            cout<< (cur_val & nums[j]) <<endl;
            if((cur_val & nums[j]) == 0)
            {
                cur_val = cur_val | nums[j];
                //cout<<cur_val<<endl;
                //cout<<ans<<endl;
                //cout<<j<<endl;
                ans++;
                j++;
                //i++;
                max_val = max(max_val, ans);
            }
            else
            {
                i++;
                ans = 0;
                j++;
                cur_val = nums[i];
            }

        }
        return max_val+1;
        
    }

    */

    int ans = 0, mask = 0;
        for (int lo = -1, hi = 0; hi < nums.size(); ++hi) {
            while ((mask & nums[hi]) != 0) { // nums[hi] has duplicate set bits for current sliding window.
                mask ^= nums[++lo]; // shrink left bound of current sliding window, and remove the corresponding element.
            }
            mask |= nums[hi]; // Expand right bound and put nums[hi] into window.
            ans = max(ans, hi - lo); // update the max window size.
        }
        return ans;
    }
};