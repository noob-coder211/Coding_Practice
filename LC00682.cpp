class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> s;
        string plus = "+";
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i] == "C")
                s.pop();
            else if(operations[i] == "D")
            {
                string num = s.top();
                int val = stoi(num);
                s.push(to_string(val*2));
            }
            else if(operations[i] == plus)
            {
                string num = s.top();
                int first = stoi(num);
                s.pop();
                string num2 = s.top();
                int second = stoi(num2);
                s.push(num);
                s.push(to_string(first+second));
            }
            else
                s.push(operations[i]);
        }
        int ans = 0;
        while(s.size()>0)
        {
            string num = s.top();
            ans+= stoi(num);
            s.pop();
        }
        return ans;

        
    }
};