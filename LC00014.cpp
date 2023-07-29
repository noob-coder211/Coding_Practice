class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        int flag = 0;
        while(index< strs[0].size() && flag == 0){
        for(int i=1;i<strs.size();i++)
        {
            if(index >= strs[i].size() || strs[i][index] != strs[0][index])
            {flag = 1;
             index--;
                break;}
        }
            index++;
        }
        return strs[0].substr(0, index);
        
    }
};