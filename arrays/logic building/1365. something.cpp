vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        int count[101] = {0};

        for(int i : nums)
        {
            count[i]++;
        }

        for(int i = 1; i < 101; i++)
        {
            count[i] += count[i-1];
        }

        for(int i : nums)
        {
            if(i == 0)
            {
                result.emplace_back(0);
                continue;
            }
            result.emplace_back(count[i-1]);
        }

        return result;

    }
