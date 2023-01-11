int splitArray(vector<int>& nums, int k) {
        /* the maximum sum when the array is not split will be the highest. lets find it.
        // the maximum sum when the array is split into most parts possible is the maximum element and least.
        // so for 0 partitions, maxSum = sum of all elements
        // for nums.size() partitions, maxSum = max element in the array
        // for k (0 <= k <= nums.size()) partitions, maxSum = (sum of all ele, max ele); You can use Binary
        // Search in this maxSum range. Create partitions based on the mid sum then if number of partitions 
        // made is equal to k -- that is a possibility but we need to see that for what all sum possibilities
        // in this range that result into k partitions, which one is minimum (in maxSum range)?
        */

        int minMaxSum = 0;
        int maxMaxSum = 0;
        int maxAns = 0;

        for(int i : nums)
        {
            if(minMaxSum < i)
            {
                minMaxSum = i;
            }
            maxMaxSum += i;
        }

        // Applying Binary Search in this range. [minMaxSum, maxMaxSum]
        int mid;  // now treat minMaxSum as start and maxMaxSum as end.
        while(minMaxSum <= maxMaxSum)
        {
            
            // now determine how many splits would be needed to obtain sum of splits less than or equal to mid.
            int splitsNeeded = 1;           // one partition is always there i.e. the array itself.
            int auxSum = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                mid = minMaxSum + (maxMaxSum-minMaxSum)/2;
                if(auxSum + nums[i] > mid)
                {
                    splitsNeeded++;
                    auxSum = nums[i];
                }
                else
                {
                    auxSum += nums[i];
                }
                
            }
            
            if(k >= splitsNeeded)    
            {
                maxAns = mid;
                maxMaxSum = mid - 1;
            }
            else 
            {
                minMaxSum = mid + 1;
            }
        }

        return maxAns;
    }
