class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(int num: nums)
        {
            if(m.count(num) == 0)
                m[num] = 1;
            else
                m[num]++;
        }
        int max_val = 0;
        for(auto itr=m.begin(); itr!= m.end();itr++)
        {
            if(itr->second > max_val)
            {
                max_val = itr->second;
            }
        }
        if(max_val <= n/2)
            return n%2;
        else
            return 2 * max_val - n;
        
    }
};