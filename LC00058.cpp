class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!= ' ')
                count++;
            
            if(s[i] == ' ' && count!=0)
            {
                ans = count;
                count = 0;
            }
        }
        if(count!=0)
            return count;
        return ans;
        
        
    }
};