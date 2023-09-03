class Solution {
public:
    string removeDigit(string number, char digit) {
       
        int last_index = -1;
        int drop_index = -1;
        int n = number.size();
        for(int i=0;i<n;i++)
        {
            if(number[i] == digit && i< n-1)
            {
                if(number[i+1] > number[i])
                {
                    drop_index = i;
                    break;
                }
                else
                {
                    last_index = i;
                }
            }
            else if(number[i] == digit)
                last_index = i;
        }
        if(drop_index!= -1)
        {
            return number.substr(0, drop_index ) + number.substr(drop_index+1);
        }
        else
            return number.substr(0, last_index) + number.substr(last_index+1);
        
    }
};