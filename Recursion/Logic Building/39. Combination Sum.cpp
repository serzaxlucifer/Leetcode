// Recursion Tree Model for this: https://assets.leetcode.com/users/images/a7b5e2bf-f7c5-4e3a-a040-5cb619027830_1645077072.6875963.jpeg

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> answer;

        vector<int> aux;

        backtracker(candidates, answer, aux, target, 0, 0);

        return answer;
    }

    void backtracker(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& aux, int target, int level, int sum)
    {
        if(sum >= target || level == candidates.size())
        {
            if(sum == target)
            {
                answer.push_back(aux);
            }
            return;
        }

        // Include (and Include again?)

        aux.push_back(candidates[level]);
        backtracker(candidates, answer, aux, target, level, sum + candidates[level]);
        // Exclude 

        aux.pop_back();
        backtracker(candidates, answer, aux, target, level+1, sum);

    }
