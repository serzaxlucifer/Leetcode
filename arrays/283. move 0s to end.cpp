// my intial solution that involves a 2-pointer approach. Beats 82% in runtime.
void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return;
        }
        int p1 = 0;
        int p2 = 1;

        while(p2 < nums.size())
        {
            if(nums[p1] == 0)
            {
                if(nums[p2] == 0)
                {
                    p2++;
                }
                else
                {
                    nums[p1] = nums[p2];
                    nums[p2] = 0;
                    p1++, p2++;
                }
            }
            else
            {
                p1++, p2++;
            }
        }
    }

// another solution:
void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j=0;j < nums.size();j++){
            if(nums[j]!=0){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }
        }
    }

//

void moveZeroes(vector<int>& nums) {
        int snowBallSize = 0; 
        for (int i=0;i<nums.size();i++){
	        if (nums[i]==0){
                snowBallSize++; 
            }
            else if (snowBallSize > 0) {
	            int t = nums[i];
	            nums[i]=0;
	            nums[i-snowBallSize]=t;
            }
        }
    }



