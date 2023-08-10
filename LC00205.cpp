class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_map<char, char> rmap;
        if(s.size() != t.size())
            return false;
        for(int i=0;i<s.size();i++)
        {
            if(map.find(s[i]) != map.end())
            {
                if(map[s[i]] != t[i])
                    return false;
            }
            else
                map[s[i]] = t[i];

            if(rmap.find(t[i])!=rmap.end())
            {
                if(rmap[t[i]] != s[i])
                    return false;
            }
            else
                rmap[t[i]] = s[i];
        }
        return true;
        
    }
};