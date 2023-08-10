class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        int n = emails.size();
        set<string> ans;
        for(string email: emails)
        {
            int local_name = 0;
            string new_email = "";
            for(int i=0;i<email.size();i++)
            {
                if(local_name == 0 && email[i] == '+')
                {
                    while(email[i]!= '@')
                        i++;
                    i--;
                }
                else if(local_name== 0 && email[i] == '.')
                    continue;
                else if(email[i] == '@')
                {
                    local_name = 1;
                    new_email+= email[i];
                }
                else
                {
                    new_email+= email[i];
                }
            }
            //cout<<new_email<<endl;
            ans.insert(new_email);
        }
        return ans.size();
        
    }
};