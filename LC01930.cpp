class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, pair<int,int>> m;
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            if(m.count(c) ==0)
            {
                pair<int, int> p =make_pair(i, i);
                m[c] = p;
            }
            else
            {
                pair<int, int> p = m[c];
                p.second = i;
                m[c] = p;
            }
        }
        int ans = 0;
        for(auto itr = m.begin(); itr!= m.end();itr++)
        {
            char c = itr->first;
            pair<int, int> p = itr->second;
            //int p = v.size();
            unordered_set <char> set;
            int first = p.first;
            int last = p.second;
            //int last = v[p-1];
            for(int j=first+1;j<last;j++)
            {
                set.insert(s[j]);
            }
                    
            ans += set.size();
        }
        return ans;
        
    }
};