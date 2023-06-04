class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<bool> vis(n, false);
        queue<int> q;
        int ans = 0;
        //q.push(0);

        for(int i=0;i<n;i++){

            if(vis[i] == false)
            {
                q.push(i);
                ans++;
                while(q.size()>0)
                {
                    int val = q.front();
                    q.pop();
                    for(int i=0;i<n;i++)
                    {
                        if(isConnected[val][i])
                        {
                            if(!vis[i])
                            {
                                vis[i] = true;
                                q.push(i);
                            }
                        }
                    }
                }
            }

        }
        return ans;

        
    }
};