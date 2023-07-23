class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        int n = words.size();
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            string s= words[i];
            
            int start = 0;
            int end = 0;
            
            for(int j=0;j<s.size();j++)
            {
                if(s[j] == separator)
                {
                    if(j != start)
                        ans.push_back(s.substr(start, j-start));
                    start = j+1;
                }
            }
            if(start<s.size())
                ans.push_back(s.substr(start));
            
        }
        return ans;
        
    }
};