// This will be a one-stop page for the House Robber solution.
// This solution would not exist without the original solutions written over at '' by ''. This page is much of a copy of that, so to speak. I RECOMMEND
// VIEWING THE ORIGINAL POST INSTEAD OF WHAT'S BELOW!!!!

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
