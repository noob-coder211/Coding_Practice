class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {

        vector<vector<int>> map(101);
        for(auto &r: rectangles)
        {
            map[r[1]].push_back(r[0]);
        }
        for(int i=0;i<101;i++)
        {
            sort(map[i].begin(), map[i].end());
        }
        vector<int> res;
        for(auto &p: points)
        {
            int ans = 0;
            for(int i=p[1];i<101;i++)
            {
                auto lb = lower_bound(map[i].begin(), map[i].end(), p[0]);
                ans+= map[i].end() - lb;
            }
            res.push_back(ans);
        }
        return res;
        
    }
};