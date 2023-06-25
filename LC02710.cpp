class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int last = n;
        
        for(int i=n-1;i>=0;i--)
        {
            if(num[i] != '0')
                break;
            else
                last = i;
        }
        return num.substr(0, last);
        
    }
};