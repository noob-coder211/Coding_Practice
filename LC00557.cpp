class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string word = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ' ')
                word+= s[i];
            else
            {
                v.push_back(word);
                word = "";
            }
        }
        v.push_back(word);
        string ans = "";
        for(int i=0;i<v.size();i++)
        {
            string word = v[i];
            reverse(word.begin(), word.end());
            ans += word;
            if(i< v.size()-1)
                ans += ' ';
        }
        
        return ans;
        
    }
};