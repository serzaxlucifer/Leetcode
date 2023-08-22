class Solution {
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
