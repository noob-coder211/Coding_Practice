class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n>m)
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        n = nums1.size();
        m = nums2.size();
        int total = (n+m);
        int partition = (total)/2;

        int l = 0;
        int r = n-1;

        while(true){
            //cout<<l<<" "<<r<<endl;  
            int i = (l+r)/2;
            
            if(l+r<0)
                i = (l+r-1)/2;
            int j = partition -i-2;
            //cout<<i<<" "<<j<<endl;
            int Aleft = i<0? INT_MIN: nums1[i];
            int Aright = i+1>=n ? INT_MAX: nums1[i+1];
            int Bleft = j<0? INT_MIN: nums2[j];
            int Bright = j+1>=m? INT_MAX: nums2[j+1];

            if (Aleft <= Bright && Bleft <= Aright)
            {
                if (total%2 == 0)
                    return (max(Aleft,Bleft)+min(Aright, Bright))/2.0;
                else
                    return min(Aright, Bright);
            }
            else if(Aleft> Bright)
                r = i-1;
            else
                l = i+1;
        }

        
    }
};