class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> map;
        unordered_map<string, char> rmap;

        vector<string> words;
        string word = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
                word+= s[i];
        }
        words.push_back(word);
        if(pattern.size() != words.size())
            return false;

        for(int i=0;i<pattern.size();i++)
        {
            char c = pattern[i];
            //cout<<c<<endl;
            if(map.count(c) == 0){
                map[c] = words[i];
            }
            else
            {
                if(map[c]!= words[i])
                    return false;
            }
            //cout<<map[c]<<endl;

            string word = words[i];
            //cout<<word<<endl;

            if(rmap.count(word) == 0)
                rmap[word] = c;
            else
            {
                if(rmap[word]!= c)
                    return false;
            }
        }
        
        return true;
        
    }
};