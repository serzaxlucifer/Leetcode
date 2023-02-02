// CHALLENGE: Make changes in the original array itself!

vector<int> buildArray(vector<int>& nums) 
    {
        // O(1) space challenge!
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            nums[i] += (nums[nums[i]]%size)*size;       // mind blowing logic!!!!
        }
        
        for (int i = 0; i < size; i++)
        {
            nums[i] /= size;
        }

        return nums;
    }
