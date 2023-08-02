class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int flag = 0;

        int i = 0;
        int j = n-1;

        int n_i = i;
        int n_j = j;
        //int n_flag = 0;

        while(i<j)
        {
            //cout<<s[i] <<" "<<s[j]<<endl;
            if(s[i] != s[j] && flag == 2)
            {
                return false;
            }
            else if(s[i]!= s[j] && flag == 1){
                i = n_i;
                j = n_j;
                i++;
                flag = 2;
            }
            else if(s[i] != s[j])
            {
                flag = 1;
                n_i = i;
                n_j = j;
                j--;
            }
           else{
            i++;
            j--;}
        }
        return true;
        
        
    }
};