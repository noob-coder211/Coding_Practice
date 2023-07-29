class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<string> temp = strs;

        map<string, vector<int>> order;

        for(int i=0;i<temp.size();i++)
        {
            string s = temp[i];
            sort(s.begin(), s.end());

            if(order.count(s)!= 0 )
            {
                vector<int> v = order[s];
                v.push_back(i);
                order[s] = v;
            }
            else
            {
                vector<int> v;
                v.push_back(i);
                order[s] = v;
            }
        }

        vector<vector<string>> ans;

        for(auto itr = order.begin(); itr!= order.end();itr++)
        {
            vector<int> v = itr->second;

            vector<string> fin;

            for(int index: v)
            {
                fin.push_back(strs[index]);
            }
            ans.push_back(fin);
        }
        return ans;


        
    }
};