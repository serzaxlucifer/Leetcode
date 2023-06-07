int jump(vector<int>& nums) 
    {
        // Problem 55, just tougher. Let's try a similar logic. 
        
        int size = nums.size();     // how many elements?
        
        int farthestJump = 0;
        int updateIndex = 0;
        int solution = 0;

        for(int i = 0; i < size-1; i++)
        {
            farthestJump = max(i + nums[i], farthestJump);

            if(updateIndex == i)
            {
                solution++;        // ideal jump was found.
                updateIndex = farthestJump;
            }
        }

        return solution;
        
    }

// Utilize principles of Greedy Approach and Dynamic Paradigm. The hard part is how to use them, right?!
