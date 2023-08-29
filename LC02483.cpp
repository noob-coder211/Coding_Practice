class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.size();
        vector<int> n_left(n+1, 0);
        vector<int> y_right(n+1, 0);
        int count = 0;
        for(int i=1;i<=n;i++)
        {
            if(customers[i-1] == 'N')
                count++;
            n_left[i] = count;
        }
        count = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(customers[i] == 'Y')
                count++;
            y_right[i] = count;
        }
        int ans = INT_MAX;
        int ans_index = -1;
        for(int i=0;i<=n;i++)
        {
            int tp = n_left[i] + y_right[i];
            if(ans>tp)
            {
                ans = tp;
                ans_index = i;
            }
        }
        return ans_index;
    }
};