// This is a tough and VERY IMPORTANT question! Let's try to uncover multiple approaches, seeking optimality.

// Brute Force:

int minimumDifference(vector<int>& nums)         // obviously gives TLE!
    {
        int minn = INT_MAX;          // Globalized

        permute_helper(nums, 0, nums.size()-1, minn);

        return minn;
    }

    void permute_helper(vector<int>& nums, int l, int r, int &minn)
    {
        if(l == r)
        {
            // This is a permutation.
            int sum1 = 0, sum2 = 0;

            for(int i = 0; i <= r; i++)
            {
                if(i < (r+1)/2)
                {
                    sum1 += nums[i];
                }
                else
                {
                    sum2 += nums[i];
                }
            }
            minn = min(minn, abs(sum1 - sum2));

            return;
        }

        for(int i = l; i <= r; i++)
        {
            swap(nums[l], nums[i]);
            permute_helper(nums, l+1, r, minn);
            swap(nums[l], nums[i]);
        }
    }

// 
