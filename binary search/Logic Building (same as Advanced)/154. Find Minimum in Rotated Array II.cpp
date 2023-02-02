// Leetcode HARD  --  Same as Part 1 but with duplicates existing in it!      |     But as usual, my brain is too small to figure things out. Nvm.. moving on!

int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            else if (nums[mid] < nums[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same: GOLDEN TICKET!
                hi--;   // just remove it from end!
            }
        }
        return nums[lo];
    }
