class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int m = wall[0].size();

        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = wall[i][0];
            for(int j=1;j<wall[i].size();j++)
            {
                sum+= wall[i][j];
                wall[i][j] = sum;
            }

        }
        int ans = 0;
        unordered_map<int, int> map;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<wall[i].size()-1;j++)
            {
                int val = wall[i][j];
                if(map.count(val) == 0){
                    map[val] = 1;
                }
                else
                    map[val]++;
            }
        }
        for(auto itr: map)
        {
            //cout<<itr.first<<" "<<itr.second<<endl;
            ans = max(ans, itr.second);
        }
        return n - ans;

        
    }
};