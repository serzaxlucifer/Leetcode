bool canJump(vector<int>& nums) {
        int size = nums.size();
        int reach = size - 1;       // i wanna reach here bruh!

        for(int i = size - 2; i >= 0; i--)
        {
            if(i + nums[i] >= reach)
            {
                // I can reach the reaching point from here. But can I reach here?
                reach = i;
            }
        }

        return reach == 0;
    }
