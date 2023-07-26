
#include <iostream>
#include <string>
class Solution {
public:
    int isVowel(char ch)
        {
            // Make the list of vowels
            string str = "aeiouAEIOU";
            return (str.find(ch) != string::npos);
        }
  
    
    string sortVowels(string s) {
        vector<char> v;
        
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                v.push_back(s[i]);
            }
        }
        sort(v.begin(), v.end());
        int cur = 0;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = v[cur];
                cur++;
            }
        }
        return s;
        
    }
};