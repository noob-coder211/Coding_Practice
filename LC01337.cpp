class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>soldiers(n,0);
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<m;j++)
            {   if(mat[i][j] == 1)
                    count++;
                else
                    break;
            }
            soldiers[i] = count;
        }
        vector<pair<int, int>> sort_count;
        for(int i=0;i<n;i++)
        {
            sort_count.push_back(make_pair(soldiers[i], i));
        }
        sort(sort_count.begin(), sort_count.end());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(sort_count[i].second);
        }
        return ans;

        
    }
};