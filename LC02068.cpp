class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> freq1, freq2;
        for(char c: word1)
        {
            if(freq1.count(c) == 0)
                freq1[c] = 1;
            else
                freq1[c]++;
        }

        for(char c: word2)
        {
            if(freq2.count(c) == 0)
                freq2[c] = 1;
            else
                freq2[c]++;
        }

        for(char c : word1)
        {
            if(freq2.count(c)!=0)
            {
                if(abs(freq1[c] - freq2[c]) >3)
                    return false;
            }
            else
            {
                if(freq1[c] > 3)
                    return false;
            }
        }

        for(char c : word2)
        {
            if(freq1.count(c)!=0)
            {
                if(abs(freq1[c] - freq2[c]) >3)
                    return false;
            }
            else
            {
                if(freq2[c] > 3)
                    return false;
            }
        }
        return true;
    }
};