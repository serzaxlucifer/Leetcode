// O(n) Solution:

int minSubArrayLen(int target, vector<int>& nums)       // Beats 99.88% solution in runtime. 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int size = nums.size();
        int minLen = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;

        while(end < size)
        {
            sum+=nums[end];
            while(sum >= target)
            {
                minLen = minLen < (end-start+1) ? minLen : end-start+1;
                sum -= nums[start++];
            }
            end++;
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }

// O(nlogn) Solution:

