// first brute force implementation: O(n) TC & O(n) SC

vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int prefix[size];                     // prefix array
        int suffix[size];                     // suffix array
        prefix[0] = suffix[size-1] = 1;
        vector<int> result;

        // Suffix Generation:
        for(int i = size - 2; i >= 0; i--)
        {
            suffix[i] = (suffix[i+1] * nums[i+1]);
        }           

        // Prefix Generation:
        for(int i = 1; i < size; i++)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        // Result Generation:
        for(int i = 0; i < size; i++)
        {
            result.emplace_back(prefix[i]*suffix[i]);
        }

        return result;

    }

// This does the same thing. [THE MORE YOU KNOW!]
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums), suf(nums), ans(size(nums));
        partial_sum(begin(pre), end(pre), begin(pre), multiplies<int>());       // calculates & stores prefix product at each index
        partial_sum(rbegin(suf), rend(suf), rbegin(suf), multiplies<int>());    // calculates & stores suffix product at each index
        for(int i = 0; i < size(nums); i++)
            ans[i] = (i ? pre[i-1] : 1) * (i+1 < size(nums) ? suf[i+1] : 1);
        return ans;
    }

// -----------

// But we are required to do in O(1) space complexity (which does not include space occupied by result vector).

// Better Solution: (the above solution seems trashy in comparison to this!)
vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> result(size , 1);
        int k = 1;     

        for(int i = 0; i < size; i++)
        {
            result[i] *= (k);
            k *= nums[i]; 
        }
        k = 1;

        for(int i = size - 1; i >= 0; i--)
        {
            result[i] *= (k);
            k *= nums[i]; 
        }

        return result;

    }

// Let's further up the challenge! Perform all the above else in one loop and no additional space.

vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        
        int prefix = 1, suffix = 1;
        vector<int> result(size, 1);

        for(int i = 0; i < size; i++)
        {
            result[i] *= prefix;
            prefix *= nums[i];                          // update prefix
            result[size - 1 - i] *= suffix;
            suffix *= nums[size - 1 - i];               // update suffix
        }

        return result;

    }

// PS. Never count on Leetcode's Runtime evaluator. It's highly variable as per timing.
