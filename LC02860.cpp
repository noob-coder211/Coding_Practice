class Solution {
public:
    int countWays(vector<int>& nums) {
        
        int ans = 0;
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        nums.push_back(1e5+1);
        for(int i=0;i<=n;i++)
        {
            if(s.count(i)==0)
            {
                if(nums[i]>i)
                {
                    if(i>0)
                    {
                        if(nums[i-1] < i)
                            ans++;
                    }
                    else{
                    ans++;}
                }
            }
        }
        return ans;
        
    }
};