class Solution {
public:

    bool pairsort(const pair<int, int> &p1, const pair<int, int> &p2){
        return p1.first > p2.first;}

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        int n = nums.size();

        for(int num: nums)
        {
            if(freq.count(num) == 0)
                freq[num] = 0;
            else
                freq[num]++;
        }
        vector<pair<int, int>> index;

        for(auto itr= freq.begin(); itr!= freq.end();itr++){
            int value = itr->first;
            int count = itr->second;

            index.push_back(make_pair(count, value));
        }

        sort(index.begin(), index.end());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(index[index.size() - i -1].second);
        }
        return ans;
        
    }
};