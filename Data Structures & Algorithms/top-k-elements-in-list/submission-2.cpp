class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> mpp;

        vector<vector<int>> bucket(n + 1);

        // Count frequency
        for(auto it : nums)
        {
            mpp[it]++;
        }

        // Put elements into frequency buckets
        for(auto &i : mpp)
        {
            int element = i.first;
            int frequency = i.second;

            bucket[frequency].push_back(element);
        }

        vector<int> result;

        // Start from highest frequency
        for(int i = n; i >= 0; i--)
        {
            if(bucket[i].size() == 0)
                continue;

            for(int value : bucket[i])
            {
                result.push_back(value);
            }

            if(result.size() == k)
                return result;
        }

        return result;
    }
};