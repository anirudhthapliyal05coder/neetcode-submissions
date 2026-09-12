class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // 1. Store product of everything to the LEFT
        int prefix = 1;

        for(int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        // 2. Multiply by product of everything to the RIGHT
        int suffix = 1;

        for(int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};