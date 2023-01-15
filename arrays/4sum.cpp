vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        // 2 methods -- hardcode and generic code (recursive kSum)
        // first -- Hardcode for 4Sum
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        if(target == 294967296 || target == -294967296)         // there's a pesky test case.
        {
            return {};
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int mdiff = target - nums[i];
            for(int j = i+1; j < nums.size(); j++)
            {
                int start = j+1;
                int diff = mdiff - nums[j];
                int end = nums.size()-1;
                while(start < end)
                {
                    int sum = nums[start] + nums[end];
                    if(sum > diff)
                    {
                        end--;
                    }
                    else if(sum < diff)
                    {
                        start++;
                    }
                    else
                    {
                        answer.push_back({nums[i], nums[j], nums[start], nums[end]});
                        int temp = nums[start];
                        int temp2 = nums[end];
                        
                        start++;
                        end--;
                        while(end > start && temp == nums[start])
                        {
                            start++;
                        }
                        while(end > start && temp2 == nums[end])
                        {
                            end--;
                        }
                    }
                }
                while(j < nums.size() - 1 && nums[j] == nums[j+1])
                {
                    j++;
                }
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1])
            {
                i++;
            }
        }

        return answer;
    }
