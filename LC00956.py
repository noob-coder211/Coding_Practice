class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        # dp[taller - shorter] = taller
        dp = {0:0}
        
        for r in rods:
            # dp.copy() means we don't add r to these stands.
            new_dp = dp.copy()
            for diff, taller in dp.items():
                shorter = taller - diff
                
                # Add r to the taller stand, thus the height difference is increased to diff + r.
                new_dp[diff + r] = max(new_dp.get(diff + r, 0), taller + r)
                class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        # dp[taller - shorter] = taller
        dp = {0:0}
        
        for r in rods:
            # dp.copy() means we don't add r to these stands.
            new_dp = dp.copy()
            for diff, taller in dp.items():
                shorter = taller - diff
                
                # Add r to the taller stand, thus the height difference is increased to diff + r.
                new_dp[diff + r] = max(new_dp.get(diff + r, 0), taller + r)
                
                # Add r to the shorter stand, the height difference is expressed as abs(shorter + r - taller).
                new_diff = abs(shorter + r - taller)
                new_taller = max(shorter + r, taller)
                new_dp[new_diff] = max(new_dp.get(new_diff, 0), new_taller)
                
            dp = new_dp
            
        # Return the maximum height with 0 difference.
        return dp.get(0, 0)

"""
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {

        //dp[taller - shorter] = taller

        unordered_map<int, int> m;
        m[0] = 0;
        int n = rods.size();
        for(int i=0;i<n;i++)
        {
            int r = rods[i];
            unordered_map<int, int> new_m = m;
            for(auto itr =  new_m.begin(); itr!= new_m.end(); itr++)
            {
                int diff  = itr->first;
                int taller = itr->second;
                int shorter = taller - diff;

                // Add to taller
                int newtaller = 0;
                if (new_m.count(diff+r) != 0)
                    newtaller = max(newtaller, new_m[diff+r]);
                new_m[diff+r] = max(newtaller, taller+r);

                // Add to shorter
                int newdiff = abs(shorter+r-taller);
                int newtaller2 = 0;
                if(new_m.count(newdiff) !=0)
                    newtaller2 = max(newtaller2, new_m[newdiff]);
                new_m[newdiff] = max(shorter+r, max(taller, newtaller2));

                //cout<<newdiff<<endl;

            }
            m = new_m;

        }
        return m[0]; 
        
    }
};
"""
                # Add r to the shorter stand, the height difference is expressed as abs(shorter + r - taller).
                new_diff = abs(shorter + r - taller)
                new_taller = max(shorter + r, taller)
                new_dp[new_diff] = max(new_dp.get(new_diff, 0), new_taller)
                
            dp = new_dp
            
        # Return the maximum height with 0 difference.
        return dp.get(0, 0)

"""
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {

        //dp[taller - shorter] = taller

        unordered_map<int, int> m;
        m[0] = 0;
        int n = rods.size();
        for(int i=0;i<n;i++)
        {
            int r = rods[i];
            unordered_map<int, int> new_m = m;
            for(auto itr =  new_m.begin(); itr!= new_m.end(); itr++)
            {
                int diff  = itr->first;
                int taller = itr->second;
                int shorter = taller - diff;

                // Add to taller
                int newtaller = 0;
                if (new_m.count(diff+r) != 0)
                    newtaller = max(newtaller, new_m[diff+r]);
                new_m[diff+r] = max(newtaller, taller+r);

                // Add to shorter
                int newdiff = abs(shorter+r-taller);
                int newtaller2 = 0;
                if(new_m.count(newdiff) !=0)
                    newtaller2 = max(newtaller2, new_m[newdiff]);
                new_m[newdiff] = max(shorter+r, max(taller, newtaller2));

                //cout<<newdiff<<endl;

            }
            m = new_m;

        }
        return m[0]; 
        
    }
};
"""