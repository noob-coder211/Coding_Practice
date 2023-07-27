class Solution {
public:
    uint32_t reverseBits(uint32_t n) {



        string s = "";
        while(n>0)
        {
            if(n%2 == 1)
                s+='1';
            else
                s+= '0';
            n = n/2; 
        }
        cout<<s<<endl;
        //reverse(s.begin(), s.end());
        while(s.size() < 32)
            s+= '0';
        uint32_t ans = 0;
        for(int i=0;i<s.size();i++)
        {
            cout<<i<<" "<<s[i]<<" "<<ans<<endl;
            ans = ans *2 + s[i] - '0';
        }
        return ans;
        
    }
};