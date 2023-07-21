class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        int n = asteroids.size();

        stack<int> s;
        s.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++)
        {
            if(asteroids[i] > 0)
                s.push(asteroids[i]);
            else
            {
                if(s.size() == 0)
                    s.push(asteroids[i]);
                else
                {
                    int right = s.top();
                    if(right<0)
                    {
                        s.push(asteroids[i]);
                        continue;
                    }
                    while(s.size() > 0 && right < abs(asteroids[i]))
                    {
                        s.pop();
                        if(s.size() == 0)
                            break;
                        right = s.top();
                        if(right < 0)
                            {s.push(asteroids[i]);
                            break;}
                    }
                    if(s.size() == 0)
                        s.push(asteroids[i]);
                    if(right == abs(asteroids[i]))
                        s.pop();
                    
                }
            }
        }
        while(s.size() > 0 )
        {
            int val = s.top();
            ans.push_back(val);
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};