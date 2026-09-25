class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         int n = position.size();

        // Store {position, speed}
        vector<pair<int, int>> cars;

        for(int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());
        
        stack<double> st;
        for(int i=0;i<n;i++)
        {
            int pos=cars[i].first;
            int speed=cars[i].second;

            double time=(double)(target - pos) / speed;

            if(st.empty()||time>st.top())
            {
                st.push(time);
            }
        }
        return st.size();

    }
};
