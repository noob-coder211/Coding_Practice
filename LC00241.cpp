class Solution {
public:

    vector<int> dp(string s, unordered_map<string, vector<int>> repeat)
    {
        vector<int> ans;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                string str1 = s.substr(0, i);
                string str2 = s.substr(i+1);
                vector<int> val1, val2;
                if(repeat.count(str1) !=0)
                    val1 = repeat[str1];
                else
                    val1 = dp(str1, repeat);
                if(repeat.count(str2) !=0)
                    val2 = repeat[str2];
                else
                    val2 = dp(str2, repeat);

                for(auto v1: val1)
                {
                    for(auto v2: val2)
                    {
                        if(s[i] == '+')
                            ans.push_back(v1+v2);
                        else if(s[i] == '-')
                            ans.push_back(v1-v2);
                        else if(s[i] == '*')
                            ans.push_back(v1*v2);
                    }
                }
                
            }
        }
        if(ans.size() == 0)
            ans.push_back(stoi(s));
        repeat[s] = ans;
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> repeat;
        return dp(expression, repeat);
    }
};