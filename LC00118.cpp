class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> first;
        first.push_back(1);
        if(numRows == 0)
            return ans;
        ans.push_back(first);
        if(numRows == 1)
            return ans;
        first.push_back(1);
        ans.push_back(first);
        if(numRows == 2)
            return ans;
        for(int i=3;i<=numRows;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            vector<int> prev = ans[i-2];
            for(int j=0;j<prev.size()-1;j++)
            {
                int sum = prev[j] + prev[j+1];
                temp.push_back(sum);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
        
    }
};