class Solution {
public:
    int maxNumberOfBalloons(string text) {

        map<char, int> freq;

        for(char c: text)
        {
            if(freq.count(c) == 0)
                freq[c] = 1;
            else
                freq[c]++;
        }

        string s = "balon";
        int ans = INT_MAX;
        for(char c: s)
        {
            if(c == 'l' || c == 'o')
            {
                int val1 = freq['l']/2;
                int val2 = freq['o']/2;
                ans = min(ans, min(val1, val2));
            }
            else
                ans = min(ans, freq[c]);
        }
        return ans;
        
    }
};