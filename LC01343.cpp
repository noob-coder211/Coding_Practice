class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;

        int sum = 0;
        for(int i=0;i<k;i++)
        {
            sum+= arr[i];
        }
        for(int i=k;i<arr.size();i++)
        {
            if(sum/k>= threshold)
                ans++;
            sum = sum - arr[i-k];
            sum = sum+ arr[i];
        }
        if(sum/k>= threshold)
            ans++;
        return ans;
        
    }
};