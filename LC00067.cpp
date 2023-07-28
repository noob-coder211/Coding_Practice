class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.size();
        int m = b.size();
        
        if(n>m)
        {
            while(b.size()<a.size())
                b = '0' + b;
        }
        else   
        {
            while(b.size()>a.size())
                a = '0' + a;
        }
        
        char carry = '0';
        string ans = "";
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i] == '0' && b[i] == '0')
            {
                ans = carry + ans;
                carry = '0';
            }
            else if((a[i] == '1' && b[i] == '0') || (a[i] == '0'  && b[i] == '1'))
            {
                if(carry == '0')
                    ans = '1' + ans;
                else
                {
                    ans = '0' + ans;
                }
            }
            else
            {
                if(carry == '0')
                {ans = '0' + ans;
                    carry = '1';}
                else
                {
                    ans = '1' + ans;
                    carry = '1';
                }
            }
        }
        if(carry == '1')
            ans = '1' + ans;
        return ans;
        
    }
};