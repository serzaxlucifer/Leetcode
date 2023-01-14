// This solution involves a condition where if both values at mid, start and end are same, you minimize just that as there IS NO WAY to decide which side the value lies on.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        int mid = start + (end - start)/2;

        while(start <= end)
        {
            if(nums[mid] == target)
            {
                return true;
            }
            if(nums[mid] == nums[end] && nums[end] == nums[start])
            {
                start ++;
                end--;
            }
            else if(nums[mid] > nums[end])
            {
                // rotation needs accounting.
                if(target > nums[mid] || target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else
            {
                if(target > nums[mid] && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            mid = start + (end - start)/2;
        }

        return false;
    }
};

// another solution:
return find(nums.begin(), nums.end(), target)!=nums.end();
