class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        for(int num: nums)
        {
            if(num == target)
                return true;
        }
        return false;
    }
};