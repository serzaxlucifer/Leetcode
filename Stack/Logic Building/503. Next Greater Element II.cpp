// Refer to Part-1's explanation first.
// Here the key is to tweak our Part 1 algorithm. 
// First do what's required in Part-1. Part-2 now says that hey you can go back too so just extend the code.
// See the code here, it's self-explanatory.

    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        stack<int> st;
        vector<int> ans(nums.size(), 0);

        for(int i = 2*nums.size()-1; i >= 0; i--)    // in 2nd traversal of the array, we'll be checking from right -> left direction if greater element wasn't found on the right side.
        {
            while(!st.empty() && nums[st.top()] <= nums[i % nums.size()])
            {
                st.pop();
            }
            ans[i % nums.size()] = st.empty() ? -1 : nums[st.top()];
            st.push(i % nums.size());
        }

        return ans;
    }
