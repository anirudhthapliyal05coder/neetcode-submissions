class Solution {
public:

    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int i, int j) {

        while(i < j) {

            if(nums[i] + nums[j] > target) {
                j--;
            }

            else if(nums[i] + nums[j] < target) {
                i++;
            }

            else {

                // Found n2 and n3
                result.push_back({-target, nums[i], nums[j]});

                i++;
                j--;

                // Skip duplicates
                while(i < j && nums[i] == nums[i-1]) {
                    i++;
                }

                while(i < j && nums[j] == nums[j+1]) {
                    j--;
                }
            }
        }
    }


    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        if(n < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());

        // Fix n1
        for(int i = 0; i < n - 2; i++) {

            // Skip duplicate n1
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int n1 = nums[i];

            // Need n2 + n3 = -n1
            int target = -n1;

            twoSum(nums, target, i + 1, n - 1);
        }

        return result;
    }
};