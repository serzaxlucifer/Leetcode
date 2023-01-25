// my initial solution:

bool check(vector<int>& nums) {
        bool rotated = false;         // to mark if we find a rotation point. well and good if we don't! The first anomaly point is considered point of rotation.
        int size = nums.size();
        int count = 0;
        for(int i = 1; i < size; i++)
        {
            if(nums[i] < nums[i-1])
            {
                if(rotated)
                {
                    count++;
                }
                else
                {
                    rotated = true;
                    count++;
                    if(nums[size-1] > nums[0])
                    {
                        return false;
                    }
                }
            }
        }

        return (count <= 1);
        
    }

// Now to optimize we try to remove the use of 'bool rotated' as removing it will remove many if-else statements. If we use some brain (which obviously I don't have), we will come up with this:

bool check(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        for(int i = 1; i < size; i++)
        {
            if(nums[i] < nums[i-1])
            {
                count++;
            }
        }
        if(nums[0] < nums[size-1])
        {
            count++;
        }

        return (count <= 1);
        
    }
