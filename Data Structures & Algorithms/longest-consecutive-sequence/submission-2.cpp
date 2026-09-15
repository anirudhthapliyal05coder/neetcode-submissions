class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        int longest=0;

        for(auto it:nums)
        {
            st.insert(it);
        }
        for(auto i:st)
        {
            if(st.find(i-1)==st.end())
            {
                int cnt=1;
                int x=i;

                while(st.find(x+1)!=st.end())
                {
                    x=x+1;
                    cnt=cnt+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};
