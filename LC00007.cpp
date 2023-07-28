class Solution {
public:
    int reverse(int x) {

        vector<int> digits;
        int sign = 0;
        if(x<0)
            sign = 1;
        x = abs(x);
        while(x>0)
        {
            int val = x%10;
            x = x/10;
            digits.push_back(val);
        }
        int ans = 0;
        //std::reverse(digits.begin(), digits.end());

        for(int digit: digits)
        {
            //cout<<ans<<endl;
            if( sign == 0 && ans > (INT_MAX/10))
                return 0;
            if(sign == 1 && (-1 *ans) < (INT_MIN/10))
                return 0;
            ans = ans*10 + digit;
        }
        if(sign == 1)
            return -1 * ans;
        return ans;
        
    }
};