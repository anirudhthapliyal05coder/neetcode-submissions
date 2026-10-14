
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mpp;

        int left = 0;
        int maxf = 0;
        int res = 0;

        for (int right = 0; right < n; right++) {
            mpp[s[right]]++;
            maxf = max(maxf, mpp[s[right]]);

            while ((right - left + 1) - maxf > k) {
                mpp[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
