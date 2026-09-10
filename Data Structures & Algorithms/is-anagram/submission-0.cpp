class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(n!=m)
            return false;
        
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;

        for(auto i:s)
        {
            mpp1[i]++;
        }
        for(auto i:t)
        {
            mpp2[i]++;
        }
        if(mpp1==mpp2)
            return true;
        else
            return false;


        
    }
};