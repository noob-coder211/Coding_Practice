class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int  n = s.size();
        int j = n-1;
        unordered_set<char> w;
        w.insert('a');
        w.insert('e');
        w.insert('i');
        w.insert('o');
        w.insert('u');
        w.insert('A');
        w.insert('E');
        w.insert('I');
        w.insert('O');
        w.insert('U');
        while(i<j)
        {
            if(w.count(s[i])!= 0)
            {
                //cout<<i<<endl;
                //cout<<j<<endl;
                //cout<<s[j]<<endl;
                if(w.count(s[j]) != 0)
                {
                    //cout<<j<< "j"<<endl;
                    char c = s[i];
                    s[i] = s[j];
                    s[j] = c;
                    i++;
                    j--;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                i++;
            }
        }
        return s;
        
    }
};