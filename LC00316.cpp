class Solution {
public:
    string removeDuplicateLetters(string s) {

        int n = s.size();
        stack<int> st;
        bool array[26];
        vector<int> last_idx(26, -1);

        for(int i=0;i<26;i++)
            array[i] = false;

        for(int i=0;i<n;i++)
        {
            int val = s[i] - 'a';
            //cout<<val<<endl;
            last_idx[val] = i;
        }
        string ans = "";
        for(int i=0;i<n;i++)
        {
            //cout<<st.size()<<endl;
            int val = s[i] - 'a';
            if(st.size() == 0)
                {st.push(val);
                array[val] = true;}
            else if (array[val] == true)
                continue;
            else
            {
                if(st.top() < val)
                {
                    st.push(val);
                    array[val] = true;
                }
                else{
                while(st.size()>0 && st.top() > val)
                {
                    if(last_idx[st.top()] > i)
                    {
                        //cout<<st.top()<<endl;
                        array[st.top()] = false;
                        st.pop();
                    }
                    else
                        break;
                }
                st.push(val);
                array[val] = true;}
            }
        }
        while(st.size()>0)
        {
            char c = 'a' + st.top();
            ans= c + ans;
            st.pop();
        }
        return ans;
        
    }
};