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

int minSubArrayLen(int target, vector<int>& nums) 
    {
        // Binary Search Solution:
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int size = nums.size();
        vector<int> prefix(size+1, 0);
        int minLen = INT_MAX;

        for(int i = 0; i < size; i++)
        prefix[i+1] = prefix[i] + nums[i];

        // From the sum array -- apply Binary Search.
        for(int i = size; i >= 0 && prefix[i] >= target; i--)
        {
            int j = upper_bound(prefix.begin(), prefix.end(), prefix[i] - target) - prefix.begin();        // length!
            minLen = (minLen < (i-j+1)) ? minLen : i-j+1;
        } 

        return (minLen == INT_MAX) ? 0 : minLen;

    }
