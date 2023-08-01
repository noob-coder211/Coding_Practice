class Solution {
public:
    vector<vector<int>> ans;

    void recur(vector<int>& A, int index, int k)
    {

        if(index>= A.size())
            return;

        vector<vector<int>> new_ans = ans;
        for(vector<int> v: ans)
        {
            if(v.size() < k)
            {
                vector<int> n_v = v;
                n_v.push_back(A[index]);
                new_ans.push_back(n_v);
            }
            else if (v.size() >= k)
            {
                continue;
            }
        }
        ans = new_ans;

        recur(A, index+1, k);

    }


    vector<vector<int>> combine(int n, int k) {
        ans.clear();

        vector<int> A;
        for(int i=1;i<=n;i++)
        {
            A.push_back(i);
        }

        vector<int> v;
        ans.push_back(v);

        recur(A, 0, k);

        vector<vector<int>> f;

        for(vector<int> v: ans)
        {
            if(v.size() == k)
                f.push_back(v);
        }
        return f;
        
    }
};