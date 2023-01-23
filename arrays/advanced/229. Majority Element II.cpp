vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = -1;    int count1 = 0;     // you can allot any random value to candidate1 and 2
        int candidate2 = -1;    int count2 = 0;
        int size = nums.size();

        for(int i = 0; i < size; i++)                      // Voting Phase
        {
            if(nums[i] == candidate1)
            {
                count1++;
            }
            else if(nums[i] == candidate2)
            {
                count2++;
            }
            else if(count1 == 0)
            {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                candidate2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--; count2--;
            }
        }

        // Verification Phase;
        count1 = count2 = 0;
        for(int i = 0; i < size; i++)
        {
            if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
        }

        vector<int> ans;
        if(count1 > size/3)
        {
            ans.push_back(candidate1);
        }
        if(count2 > size/3)
        {
            ans.push_back(candidate2);
        }

        return ans;
    }
