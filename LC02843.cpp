class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low;i<=high;i++)
        {
            int count = 0;
            int temp = i;
            while(temp>0)
            {
                temp = temp/10;
                count++;
            }
            if(count %2 == 1)
                continue;
            else
            {
                string s = to_string(i);
                int n = s.size();
                int left = 0;
                for(int i=0;i<n/2;i++)
                {
                    left+= (int)s[i];
                }
                int right = 0;
                for(int i=n/2;i<n;i++)
                {
                    right+= (int) s[i];
                }
                if(left == right)
                    ans++;
            }
            
        }
        return ans;
        
    }
};