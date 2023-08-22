class Solution {            // LeetCode Editorial Solution
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> answer;
        vector<int> temp;

        permute_helper(nums, answer, temp);

        return answer;
    }

    void permute_helper(vector<int>& nums, vector<vector<int>>& answer, vector<int>& temp)
    {
        if(nums.size() == temp.size())
        {
            answer.push_back(temp);
            return;
        }

        // If not then what do we do?

        for(int i = 0; i < nums.size(); i++)
        {
            if(temp.size() == 0)
            {
                temp.push_back(nums[i]);
                permute_helper(nums, answer, temp);
                temp.pop_back();
            }
            else
            {
                bool find = true;
                for(int j = 0; j < temp.size(); j++)
                {
                    if(temp[j] == nums[i])
                    {
                        find = false;
                        break;
                    }
                }

                if(find)
                {
                    temp.push_back(nums[i]);
                    permute_helper(nums, answer, temp);
                    temp.pop_back();
                }
            }
        }
        
        
    }
};

// LOC is too high in above code. Can we reduce the lines of code?
// Another logic to backtrack and generate same output: (courtesy of Love Babbar ['CodeHelp by Love Babbar' on YouTube])
// This is as optimized as this can get both time and space wise.
// Code Inspiration: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> answer;

        permute_helper(nums, answer, 0, nums.size()-1);

        return answer;
    }

    void permute_helper(vector<int>& nums, vector<vector<int>>& answer, int l, int r)
    {
        
        if(l == r)
        {
            answer.push_back(nums);
            return;
        }

        for(int i = l; i <= r; i++)
        {
            swap(nums[l], nums[i]);
            permute_helper(nums, answer, l+1, r);
            swap(nums[l], nums[i]);
        }
    }
};
