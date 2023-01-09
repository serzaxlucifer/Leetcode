class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int fullSum = 0;
        for(int i : nums) {
            fullSum += i;
        }

        int leftSum = 0;
        int rightSum = fullSum;

        for(int i = 0; i < nums.size(); i++)
        {
            rightSum -= nums[i];
            if(leftSum == rightSum)
            {
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};
