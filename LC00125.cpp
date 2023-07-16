#include <cctype>
#include <iostream>
#include<bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(string s) {

        int size = s.size();
        string n = "";
        cout<<size<<endl;
        int skipped = 0;
        for(int i=0;i+skipped<s.size();i++)
        {
            if(s[i+skipped] >= 'A' && s[i+skipped] <= 'Z')
                s[i] =  (char)tolower(s[i+skipped]);
            else if(s[i+skipped] >='a' && s[i+skipped] <='z')
                s[i] = s[i+skipped];
            else if(s[i+skipped] >= '0' && s[i+skipped] <= '9')
                s[i] = s[i+skipped];
            else
                {   skipped++;
                    s[i] = s[i+skipped];
                    i--;}
        }
        int n_size = s.size()-skipped;
        //cout<<s[n_size]<<endl;
        for(int i=0;i<n_size/2;i++)
        {
            if(s[i] != s[n_size - i-1])
                return false;
            
        }
        return true;
        
    }
};