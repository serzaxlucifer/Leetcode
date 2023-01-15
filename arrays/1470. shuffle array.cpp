// initial solution: TC: O(n) and SC: O(n)

vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> output;
        for(int i = 0; i < n; i++)
        {
            output.emplace_back(nums[i]);
            output.emplace_back(nums[n+i]);
        }
        return output;
    }

/*
  Now here comes the challenge! CAN WE DO IT IN PLACE i.e. without creating another vector, in given vector itself? TC: O(n) and SC: O(1)
  So, we can't store the numbers in some additional space. Additionally, rewriting a number will erase the previous value. Hence, here the interviewer would like to check our understanding of bit manipulation.
  Note that the constraint of the problem says nums[i], at maximum is: 10^3 (you need first 10 bits only to store this number).
  Using Bit Manipulation:
*/

vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = n; i < 2*n; i++)
        {
            int mask = nums[i] << 10;
            nums[i-n] |= mask;
        }

        int mask = pow(2, 10) - 1; // 0000000000 1111111111

        for(int i = n-1; i >= 0; i--)
        {
            int secondNum = nums[i] >> 10;
            int firstNum = nums[i] & mask;
            nums[2*i+1] = secondNum;
            nums[2*i] = firstNum;
        }

        return nums;
    }

// another solution (most memory efficient):

vector<int> shuffle(vector<int>& nums, int n) {
        int max_val = 1024, max_shift = 10;
        int i = 0, j = n, k = 0;
        for(; i < n; i+=2, ++j, ++k){
            nums[i] += (nums[k] % max_val)<<max_shift;
            nums[i+1] += nums[j]<<max_shift;
        }
        for(; i < j; i+=2, ++j, ++k){
            nums[i] = nums[k] % max_val;
            nums[i+1] = nums[j];
        }
        for(i = 0; i < n; ++i)
            nums[i] >>= max_shift;
        if(n%2)
            nums[n] >>= max_shift;
        return nums;
    }
