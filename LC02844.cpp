class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int z_flag = 0;
        int f_flag = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(num[i] == '0' && z_flag == 1)
                return n-i-2;
            else if(num[i] == '0')
                z_flag = 1;
            else if(num[i] == '5' && z_flag == 1)
                return n-i-2;
            else if(num[i] == '5')
                f_flag = 1;
            else if(num[i] == '2' && f_flag == 1)
                return n-i-2;
            else if(num[i] == '7' && f_flag == 1)
                return n-i-2;
        }
        if(z_flag)
            return n-1;
        return n;
    }
};