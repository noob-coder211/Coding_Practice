class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> s;

        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }

        int ans = 2;
        int cur = 2;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int num = arr[i] + arr[j];
                cur = 2;
                int second = arr[j];
                while(s.count(num) != 0)
                {
                    cur++;
                    int temp = num;
                    num = num + second;
                    second = temp;
                }
                ans = max(ans, cur);

            }
        }
        if(ans <= 2)
            return 0;
        return ans;
    }
};