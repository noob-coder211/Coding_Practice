class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int bigger = arr[n-1];
        arr[n-1] = -1;
        for(int i=n-2;i>=0;i--)
        {
            int val = arr[i];
            arr[i] = bigger;
            bigger = max(bigger, val);
        }
        return arr;
        
    }
};