// O(n^2) solution:

int maxSubArray(vector<int>& nums) 
{
    int maxSum = INT_MIN;
    for(int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < nums.size(); j++)
        {
            sum+=nums[j];
            maxSum = (maxSum < sum) ? sum : maxSum;
        }
    }

    return maxSum;
}

// O(n) --- KADANE'S ALGORITHM

int maxSubArray(vector<int>& nums) 
{
    // Kadane's Algorithm

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int maxSum = INT_MIN;
    int maxSumSoFar = 0;

    for(int i : nums)
    {
        maxSumSoFar += i;
        maxSum = (maxSum > maxSumSoFar) ? maxSum : maxSumSoFar;
        if(maxSumSoFar < 0) maxSumSoFar = 0;
    }
    return maxSum; 
}




