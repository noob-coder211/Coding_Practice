class Solution {
public:
    int minLength(string s) {
        while(true){
        int flag = 0;
        for(int i=1;i<s.size();i++)
        {
            if((s[i-1] == 'A' && s[i] == 'B') || (s[i-1] == 'C' && s[i] == 'D'))
                {
                    s.erase(i-1,2);
                    flag = 1;
                }
        }
        if(flag == 0)
            return s.size();
        }
    }
};