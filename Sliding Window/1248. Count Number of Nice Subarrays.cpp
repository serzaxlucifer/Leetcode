// Prefix Cache:

    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int odd = 0;
        unordered_map<int, int> prefix;
        int total = 0;
        prefix[0] = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] & 1)
            {
                odd++;
            }

            if(odd - k >= 0)
            {
                total += prefix[odd-k];
            }

            prefix[odd] += 1;
        }

        return total;
    }

// But the unordered_map is slowing down our algorithm. Can we do better?

// Sliding Window:
// One obvious approach is atmax(goal) - atmax(goal-1), but can we do in single pass?
// Yes!

int numberOfSubarrays(vector<int>& nums, int k) 
    {
        bool s = false;
        int start = 0;

        int odds = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] & 1)
            {
                odds++;
            }

            if(odds > k)
            {
                while(odds > k)
                {
                    if(nums[start] & 1)
                    {
                        odds--;
                    }
                    start++;
                }
            }

            if(odds == k)
            {
                s = true;
                int k = start;
                while(nums[k] % 2 == 0)
                {
                    k++; count++;
                }
            }

            if(s)
            {
                count++;
            }
        }

        return count;
    }
