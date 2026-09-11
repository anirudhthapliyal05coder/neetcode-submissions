class Solution {
    typedef pair<int,int>P;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;

        for(auto it:nums)
        {
            mpp[it]++;
        }

        priority_queue<P,vector<P>,greater<P>>pq;

        for(auto it:mpp)
        {
            int value=it.first;
            int frequency=it.second;
            pq.push({frequency,value});

            if(pq.size()>k)
            {
               pq.pop();
            }


        }
        vector<int>result;

        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
