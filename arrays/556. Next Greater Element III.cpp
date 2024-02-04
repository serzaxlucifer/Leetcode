class Solution {
public:
    int nextGreaterElement(int n) 
    {
        int digits = 0;
        string N = to_string(n);

        nextPermutation(N);

        long long ans = stoll(N);

        if(ans > INT_MAX || ans <= n)
        {
            return -1;
        }

        return ans;


    }

    void nextPermutation(string& nums) {
        int size = nums.size();
        int swapPoint = -1;
        for(int i = size-2; i >= 0; i--)
        {
            if(nums[i+1] > nums[i])
            {
                swapPoint = i;
                break;
            }
        }
        if(swapPoint < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(int i = size - 1; i > swapPoint; i--)
            {
                if(nums[swapPoint] < nums[i])
                {
                    swap(nums[swapPoint], nums[i]);
                    reverse(nums.begin()+swapPoint +1, nums.end());
                    break;
                }
            }
        }
    }
};
