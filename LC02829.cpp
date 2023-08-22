class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> s;
        int sum = 0;
        int count = 0;
        int start = 1;
        while(count<n)
        {
            if(s.count(start) == 0)
            {
                sum+= start;
                s.insert(k-start);
                count++;
            }
            start++;
        }
        return sum;
        
    }
};