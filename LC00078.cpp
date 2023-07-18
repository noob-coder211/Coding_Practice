class Solution {
public:

    vector<vector<int>> ans;

    void search(vector<int> &nums, int index)
    {
        if(index == nums.size())
            return;
        vector<vector<int>> temp = ans;
        int n = temp.size();
        for(int i=0;i<n;i++)
        {
            vector<int> vec = temp[i];
            vec.push_back(nums[index]);
            ans.push_back(vec);
        }
        search(nums, index+1);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int> vec;
        ans.push_back(vec);
        search(nums, 0);
        return ans;
        
    }
};