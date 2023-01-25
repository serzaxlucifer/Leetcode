// Brute Force (My first Solution):

void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> answer(size, 0);

        for(int i = 0; i < size; i++)
        {
            answer[(i+k)%size] = nums[i];
        }
        nums = answer;
    }

// Genius Solution:

void rotate(vector<int>& nums, int k) {
       k=k % nums.size();
       reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+k);
       reverse(nums.begin()+k,nums.end());
    }


