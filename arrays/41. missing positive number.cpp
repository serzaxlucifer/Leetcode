// my initial solution (not optimized for time):
int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());         // TC: O(logn)
        int ans = 1;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            if(nums[i]==ans) ans++;
        }

        return ans;
    }

// now this implementation uses a vector.


// the challenge is to do in TC: O(n) and SC: O(1)


