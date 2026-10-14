class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int high=0;
        int low=0;
        int ans=0;
        int maxfreq=0;
        vector<int>freq(26,0);

        while(high<n)
        {
            freq[s[high]-'A']++;
            maxfreq=max(maxfreq,freq[s[high]-'A']);
            while((high-low+1)-maxfreq>k)
            {
                freq[s[low]-'A']--;
                low++;
            }
            ans=max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};
