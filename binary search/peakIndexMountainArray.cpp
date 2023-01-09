class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int start = 0;
        int size = arr.size() - 1;
        int end = size;
        int ans = 1;
        int mid = start + ((end-start)/2);
        while(start < end)
        {
            int val = arr[mid];
            if(val < arr[mid+1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
            
            mid = start + (end-start)/2;
        }

        return start;
    }
};
