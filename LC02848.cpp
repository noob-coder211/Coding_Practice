class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> vis(101, 0);
        for(vector<int> v: nums)
        {
            int start = v[0];
            int end = v[1];
            for(int i=start;i<=end;i++)
            {
                vis[i] = 1;
            }
        }
        for(int i=0;i<=100;i++)
        {
            if(vis[i])
                ans++;
        }
        return ans;
        
    }
};