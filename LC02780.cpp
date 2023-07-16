class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        vector<int> A = nums;
        sort(A.begin(), A.end());
        int n = nums.size();
        int ele = A[n/2];
        
        vector<int> ele_count;
        vector<int> other_count;
        int e_c = 0;
        int o_c = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == ele)
            {
                e_c++;
                ele_count.push_back(e_c);
                other_count.push_back(o_c);
            }
            else
            {
                o_c++;
                ele_count.push_back(e_c);
                other_count.push_back(o_c);
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(ele_count[i] > other_count[i])
            {
                if((ele_count[n-1] - ele_count[i]) >  (other_count[n-1] - other_count[i]))
                {
                    return i;
                }
            }
        }
        return -1;
        
    }
};