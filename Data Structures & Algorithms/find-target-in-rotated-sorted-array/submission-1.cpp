class Solution {
    int findpivot(vector<int>& nums)
    {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
    int binarySearch(int l,int r,vector<int>& nums,int target)
    {
    
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivotIndex=findpivot(nums);
        int n=nums.size();

        int idx=binarySearch(0,pivotIndex-1,nums,target);

        if(idx!=-1)
            return idx;
        idx=binarySearch(pivotIndex,n-1,nums,target);
        return idx;
    }
};
