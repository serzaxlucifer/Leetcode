// This will be a one-stop page for the House Robber solution.
// This solution would not exist without the original solutions written over at '' by ''. This page is much of a copy of that, so to speak. I RECOMMEND
// VIEWING THE ORIGINAL POST INSTEAD OF WHAT'S BELOW!!!!

// Plain Recursion (first approach):

public int rob(int[] nums) {
    return rob(nums, nums.length - 1);
}
private int rob(int[] nums, int i) {
    if (i < 0) {
        return 0;
    }
    return Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));              // this is what we need to determine
}

// Recursion + Memoization (Firs Approach Optimized!)

int[] memo;
public int rob(int[] nums) {
    memo = new int[nums.length + 1];
    Arrays.fill(memo, -1);
    return rob(nums, nums.length - 1);
}

private int rob(int[] nums, int i) {
    if (i < 0) {
        return 0;
    }
    if (memo[i] >= 0) {
        return memo[i];
    }
    int result = Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    memo[i] = result;
    return result;
}

// Iterative + Memoization:

public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int[] memo = new int[nums.length + 1];
    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < nums.length; i++) {
        int val = nums[i];
        memo[i+1] = Math.max(memo[i], memo[i-1] + val);
    }
    return memo[nums.length];
}

// DP (Bottom Down):

int rob(vector<int>& nums) {
        // House Robber Solution.
        int profit1 = 0;
        int profit2 = 0;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            int tmp = profit1;
            profit1 = max(profit2 + nums[i], profit1);
            profit2 = tmp;
        }

        return profit1;
    }

// Another Solution:'

int rob(int num[], int n) {
    int a = 0;
    int b = 0;
    
    for (int i=0; i<n; i++)
    {
        if (i%2==0)
        {
            a = max(a+num[i], b);
        }
        else
        {
            b = max(a, b+num[i]);
        }
    }
    
    return max(a, b);
}
