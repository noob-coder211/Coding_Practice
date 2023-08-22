class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        columnNumber = columnNumber;
        while(columnNumber >0)
        {
            int val = (columnNumber-1)%26;
            columnNumber = (columnNumber-1)/26;
            ans = (char)('A' + val) + ans;
        }


        //char c = (char)('A' + 5);
        //cout<<c<<endl;
        return ans;
        
    }
};