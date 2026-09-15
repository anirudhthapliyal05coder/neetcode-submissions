class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        if(n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int lastSmaller = INT_MIN;
        int longest = 1;
        int count_current = 0;

        for(int i = 0; i < n; i++)
        {
            // Current number is consecutive to previous number
            if(nums[i] - 1 == lastSmaller)
            {
                count_current++;
                lastSmaller = nums[i];
            }

            // Duplicate number
            else if(nums[i] == lastSmaller)
            {
                continue;
            }

            // New sequence
            else
            {
                count_current = 1;
                lastSmaller = nums[i];
            }

            longest = max(longest, count_current);
        }

        return longest;
    }
};