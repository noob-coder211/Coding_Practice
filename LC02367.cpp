class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++)
        {
            set.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(set.count(nums[i] + diff) != 0)
            {
                if(set.count(nums[i] + 2* diff) !=0)
                    ans++;
            }
        }
        return ans;
        
    }
};