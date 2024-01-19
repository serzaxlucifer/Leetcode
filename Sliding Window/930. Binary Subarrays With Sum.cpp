// Prefix Sum: (courtesy of u/EddieCarrillo -> https://leetcode.com/problems/binary-subarrays-with-sum/solutions/186647/java-clean-solution-2-sum-prefix-sum-caching/)

/* 
In this problem we are required to find some interval [i:j] ,i < j where sum[i:j] = target. We know that sum[i:j] = A[i] + A[i+1] +... + A[j].
Then we also know that
Let's define prefixSum[j] = A[0] + A[1] + ... + A[j] 0 <= j <= n-1 (n = A.length)
It is easy to see that,
sum[i:j] = A[i] + A[i+1] ... + A[j] =
(A[0] + A[1] + ... A[i] ... + A[j]) - (A[0] + A[1] + ... A[i-1]) =
prefix[j] - prefix[i-1].

Now we the problem reduces to finding # of pairs (i, j) (i < j) such that
prefix[j] - prefix[i-1] = target
This becomes prefix[i-1] = prefix[j] - target with some algebra.
So we use the hashmap to find all pairs that satisfy the above equations.

We only need to track the prefix sum up to this point however, since we already saved all the previous results in the map.

if (sum == target) total++  
*/

int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        vector<int> prefix(nums.size()+1, 0);
        int sum = 0;
        int total = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if(sum >= goal)
            {
                total += prefix[sum-goal];
            }

            if(sum == goal)
            {
                total++;
            }

            prefix[sum]++;
        }

        return total;
    }

// sliding window:


return numSubaraysWithSUM_ATMAX(nums, goal) - numSubarraysWithSUM_ATMAX(nums, goal - 1);  // at_max is easily implemented using SL technique.
