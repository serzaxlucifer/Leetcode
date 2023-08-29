// Imprint in your brain, the logic to tackle duplicates.

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> answer;

        vector<int> aux;
        sort(nums.begin(), nums.end());

        backtracker(answer, aux, nums, 0);

        return answer;
    }

    void backtracker(vector<vector<int>>& answer, vector<int>& aux, vector<int>& nums, int index)
    {
        answer.push_back(aux);

        for(int i = index; i < nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i-1])
            {
                continue;
            }

            aux.push_back(nums[i]);
            backtracker(answer, aux, nums, i+1);
            aux.pop_back();
        }
    }
