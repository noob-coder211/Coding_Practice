/* 
https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&id=top-interview-150

Time complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(map.count(nums[i]) == 0)
                map[nums[i]] = 1;
            else
                map[nums[i]]++;

            if(map[nums[i]] > n/2)
                return nums[i];
        }
        return 0;

        
    }
};