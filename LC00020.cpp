class Solution {
public:
    bool isValid(string st) {
        
        stack<char> s;
        s.push(st[0]);
        for(int i=1;i<st.size();i++)
        {
            if(st[i] == '(' || st[i] == '{' || st[i] == '[')
                s.push(st[i]);
            else
            {
                if(s.size() == 0)
                    return false;
                char c = s.top();
                //cout<<c<<endl;
                if((st[i] == ')' && c == '(') || (st[i] == ']' && c == '[') || (st[i] == '}' && c == '{'))
                {s.pop();
                    continue;}
                else
                    return false;
            }
        }
        if(s.size()>0)
            return false;
        return true;
        
    }
};