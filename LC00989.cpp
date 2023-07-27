class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;

        vector<int> s;
        while(k>0)
        {
            s.push_back(k%10);
            k = k/10;
        }
        reverse(num.begin(), num.end());

        int n = num.size();
        int carry = 0;
        if(s.size() > n)
        {
            vector<int>temp = s;
            s = num;
            num = temp;
        }
        for(int i=0;i<num.size();i++)
        {
            if(s.size() > i)
            {
                int new_val = num[i] + s[i] + carry;
                ans.push_back(new_val%10);
                carry = new_val /10;
            }
            else
            {
                int new_val = num[i] + carry;
                ans.push_back(new_val%10);
                carry = new_val/10;
            }
        }
        if(carry>0)
            ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;

        
    }
};