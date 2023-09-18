class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        for(char c: s)
        {
            if(map.count(c)==0)
            {
                map[c] = 1;
            }
            else
                map[c]++;
        }
        vector<int> freq;
        for(auto itr = map.begin(); itr!= map.end();itr++)
        {
            freq.push_back(itr->second);
        }
        sort(freq.begin(), freq.end());
        int m = freq.size();
        int max = freq[m-1];
        vector<int> vis(max+1, 0);
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            if(vis[freq[i]] == 0)
                vis[freq[i]] = 1;
            else
            {
                int flag = 0;
                for(int j=freq[i];j>=0;j--)
                {
                    if(vis[j] == 0)
                    {
                        vis[j] = 1;
                        ans = ans + freq[i] - j;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                    ans = ans + freq[i];
            }
        }
        return ans;
        
    }
};