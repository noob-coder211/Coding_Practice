class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int n = str1.size();
        for(auto c: str2)
        {
            char t = (c == 'a') ? 'z' : c-1;
            while(i<n && (str1[i]!= c && str1[i]!=t))
                i++;
            if(i>=n)
                return false;
            i++;
        }
        return true;
        
    }
};