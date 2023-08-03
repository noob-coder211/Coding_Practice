class Solution {
public:
    vector<string> letterCombinations(string digits) {

        unordered_map<int, string> mappings;

        mappings[2] = "abc";
        mappings[3] = "def";
        mappings[4] = "ghi";
        mappings[5] = "jkl";
        mappings[6] = "mno";
        mappings[7] = "pqrs";
        mappings[8] = "tuv";
        mappings[9] = "wxyz";

        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        ans.push_back("");
        for(char digit: digits)
        {
            string poss = mappings[digit - '0'];
            vector<string> new_ans;
            //cout<<ans.size()<<endl;
            for(string s: ans)
            {
                string temp = s;
                for(char c: poss)
                {
                    temp = s;
                    //cout<<temp<<endl;
                    temp+= c;
                    new_ans.push_back(temp);
                    //cout<<temp<<endl;
                }
            }
            ans = new_ans;
        }
        return ans;
        
    }
};