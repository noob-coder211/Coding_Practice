class Solution {
public:

/*
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        //m.clear();
        sort(arr2.begin(), arr2.end());
        int ans =  dp(arr1, arr2, 0, -1);

        return ans<2001 ? ans : -1;
        
    }
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};


    unordered_map<pair<int,int>, int, pair_hash> m;
    int dp(vector<int> & arr1, vector<int> & arr2, int i, int prev)
    {
        if(i >= arr1.size())
            return 0;
        if(m.count(make_pair(i, prev)) != 0)
            return m[make_pair(i, prev)];
        int op_count = 2001;

        if(arr1[i] > prev)
            op_count = dp(arr1, arr2, i+1, prev);
        
        int idx = getright(arr2, prev);

        if(idx < arr2.size())
            op_count = min(op_count, 1+ dp(arr1, arr2, i+1, arr2[idx]));

        m[make_pair(i, prev)] = op_count;
        cout<<op_count<<endl;
        return op_count;
    }

    int getright(vector<int> arr, int val)
    {
        int l = 0;
        int r = arr.size();
        while(l<r)
        {
            int mid = (l+r)/2;
            if(arr[mid] <= val)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }

*/

short dp[2001][2001][2] = {}, max_val = 2002;
short dfs(vector<int>& t, vector<int>& s, int i, int j, bool prev_t) {
    if (i >= t.size()) 
      return 0;
    int prev = prev_t ? i == 0 ? INT_MIN : t[i - 1] : s[j];
    j = upper_bound(begin(s) + j, end(s), prev) - begin(s);
    if (dp[i][j][prev_t] == 0) {
        dp[i][j][prev_t] = max_val;
        if (j < s.size())
            dp[i][j][prev_t] = dfs(t, s, i + 1, j, false) + 1;
        if (prev < t[i])
            dp[i][j][prev_t] = min(dp[i][j][prev_t], dfs(t, s, i + 1, j, true));
    }
    return dp[i][j][prev_t];
}
int makeArrayIncreasing(vector<int>& t, vector<int>& s) {
  sort(begin(s), end(s));
  auto res = dfs(t, s, 0, 0, true);
  return res >= max_val ? -1 : res;
}
};