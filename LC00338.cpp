class Solution {
public:
    int countones(int val)
    {
        int count = 0 ;
        while(val>0)
        {
            if(val%2 == 1)
                count++;
            val=val/2;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans;

        ans.push_back(0);
        if(n>0)
        {
            ans.push_back(1);

            for(int i=2;i<=n;i++)
            {
                ans.push_back(countones(i));

            }
        }
        return ans;
        
    }
};