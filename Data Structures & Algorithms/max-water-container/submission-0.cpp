class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0, r = n - 1;
        int area = 0;

        while (l < r)
        {
            int width = r - l;

            int mini = min(heights[l], heights[r]);

            area = max(area, mini * width);

            if (heights[l] > heights[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return area;
    }
};