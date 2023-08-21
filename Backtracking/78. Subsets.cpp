// Backtracking:

vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> output;
        int length = nums.size();

        for(int i = 0; i < length+1; i++)
        {
            vector<int> combination;
            backtracking(0, combination, nums, output, i);
        }

        return output;

    }

    void backtracking(int first, vector<int>& combination, vector<int>& nums, vector<vector<int>>& output, int end)
    {
        if(combination.size() == end)
        {
            output.push_back(combination);
            return;
        }

        for(int i = first; i < nums.size(); i++)
        {
            combination.push_back(nums[i]);
            backtracking(i+1, combination, nums, output, end);
            combination.pop_back();
        }
    }

// Can we simplify our approach? https://www.youtube.com/watch?v=V0IgCltYgg4&ab_channel=CodeHelp-byBabbar

vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> output;
        int length = nums.size();
        vector<int> temp;

        backtracking(nums, temp, output, 0);

        return output;

    }

    void backtracking(vector<int>& nums, vector<int> temp, vector<vector<int>>& output, int end)
    {
        if(end == nums.size())
        {
            output.push_back(temp);
            return;
        }

        // exclude
        backtracking(nums, temp, output, end+1);
        // include
        temp.push_back(nums[end]);
        backtracking(nums, temp, output, end+1);
    }
