class Solution {
public:

    vector<int>temp;

    void merge(vector<int> & nums, int l, int mid, int r)
    {
        //temp.clear();
        int n1 = mid - l + 1;
        int n2 = r - mid;

        int start1 = l;
        int start2 = mid+1;
        

        for(int i=start1;i<start1+n1;i++)
        {
            temp[i] = nums[i];
        }
        for(int i = start2;i<start2+n2;i++)
        {
            temp[i] = nums[i];
        }

        int i=0;
        int j = 0;
        int k = l;

        while(i<n1 && j<n2)
        {
            if(temp[start1 + i] <= temp[start2 + j])
            {
                nums[k] = temp[start1+i];
                k++;
                i++;
            }
            else
            {
                nums[k] = temp[start2+j];
                j++;
                k++;
            }
        }
        while(i<n1)
        {
            nums[k] = temp[start1+i];
            i++;
            k++;
        }
        while(j<n2)
        {
            nums[k] = temp[start2+j];
            j++;
            k++;
        }

    }

    void mergesort(vector<int> & nums, int l, int r)
    {
        if(l == r)
            return;
        int mid = (l+r)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);

        merge(nums, l, mid, r);
    }


    vector<int> sortArray(vector<int>& nums) {

        for(int i=0;i<nums.size();i++)
            temp.push_back(0);

        //vector<int> temp(nums.size());
        mergesort(nums, 0, nums.size()-1);
        return nums;
        
    }
};