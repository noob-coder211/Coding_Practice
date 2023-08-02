class Solution {
public:

    vector<vector<int>> ans;

    void recur(vector<int> &nums, int index)
    {
        if(index == nums.size())
            return;
        int val = nums[index];
        vector<vector<int>> new_ans;
        for(vector<int> v: ans)
        {
            for(int i=0;i<v.size();i++)
            {
                vector<int> new_v = v;
                new_v.resize(v.size()+1);
                for(int j=v.size()-1;j>=i;j--)
                {
                    new_v[j+1] = new_v[j]; 
                }
                new_v[i] = val;
                new_ans.push_back(new_v);
            }
            v.push_back(val);
            new_ans.push_back(v);
            
        }
        ans = new_ans;
        recur(nums, index+1);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        vector<int> v;
        v.push_back(nums[0]);
        ans.push_back(v);
        recur(nums, 1);
        return ans;
        
    }
};