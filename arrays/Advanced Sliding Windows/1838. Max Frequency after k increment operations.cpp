// Sliding Window Technique:

// (A .gif representation of this Solution: https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1533899/sliding-window-visualisation/)
int maxFrequency(vector<int>& nums, int k) {
        // Sliding Window Solution
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 0;
        int size = nums.size();
        long prefixSum = 0;                                       // int results in overflow.
        int maxFreq = 1;

        for(; right < size; right++)
        {
            prefixSum += nums[right];
            if(nums[right] > (k + prefixSum)/(right-left+1))      // (nums[right]*(right-left+1) - prefixSum > k) was the original condition but causes overflow
            {
                // not feasible window
                prefixSum -= nums[left];
                left++;
            }
            maxFreq = max(maxFreq, right-left+1);
        }

        return maxFreq;
    }

// Binary Search (uses extra space for Prefix Sum Array -- Credit: leetcode.com/hiepit) [JAVA]
class Solution {
    long[] preSum;
    public int maxFrequency(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        preSum = new long[n+1];
        for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + nums[i];

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = Math.max(ans, count(nums, k, i));
        return ans;
    }
    long getSum(int left, int right) {  // left, right inclusive
        return preSum[right + 1] - preSum[left];
    }
    // Count frequency of `nums[index]` if we make other elements equal to `nums[index]`
    int count(int[] nums, int k, int index) {
        int left = 0, right = index, res = index;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long s = getSum(mid, index - 1); // get sum of(nums[mid], nums[mid + 1]...nums[index - 1])
            if (s + k >= (long)(index - mid) * nums[index]) { // Found an answer -> Try to find a better answer in the left side
                res = mid; // save best answer so far
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index - res + 1;
    }
}
