    
bool compareSecondElement(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    
    


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {


/*
        sort(intervals.begin(), intervals.end(), [] (auto &left, auto & right){
            if (left[0] == right[0])
                return left[1] < right[1];
            return left[0] < right[0];
        });

        int ans = 0;

         for(int i=0;i<intervals.size();i++)
        {
            cout<<intervals[i][0]<<endl;
        }

        vector<int> cur = intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> temp = intervals[i];
            cout<<cur[0]<<" "<<cur[1]<<endl;

            if(temp[0] < cur[1])
                ans++;
            else
            {
                cur = intervals[i];
            }
        }
        cout<<cur[0]<<" "<<cur[1]<<endl;
        return ans;

*/
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int ans = 0;
        int k = INT_MIN;
        
        for (int i = 0; i < intervals.size(); i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            
            if (x >= k) {
                // Case 1
                k = y;
            } else {
                // Case 2
                ans++;
            }
        }
        
        return ans;
    }
};