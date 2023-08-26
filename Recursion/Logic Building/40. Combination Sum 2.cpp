// An initial approach if duplicates were allowed would be:

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> answer;

        vector<int> aux;

        backtracker(candidates, answer, aux, target, 0, 0);

        return answer;
    }

    void backtracker(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& aux, int target, int level, int sum)
    {
        if(level == candidates.size())
        {
            if(sum == target)
            {
                answer.push_back(aux);
            }
            return;
        }

        // Include

        aux.push_back(candidates[level]);
        backtracker(candidates, answer, aux, target, level+1, sum + candidates[level]);
        // Exclude

        aux.pop_back();
        backtracker(candidates, answer, aux, target, level+1, sum);

    }

// BUT we need to avoid duplicates! Now, how do we do that?


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> answer;
        sort(candidates.begin(), candidates.end());

        vector<int> aux;

        backtracker(candidates, answer, aux, target, 0, 0);

        return answer;
    }

    void backtracker(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& aux, int target, int level, int sum)
    {
        if(sum == target || level == candidates.size())
        {
            if(sum == target)
            {
                answer.push_back(aux);
            }
            return;
        }

        for(int i = level; i < candidates.size(); i++)
        {
            if(i > level && candidates[i] == candidates[i-1])
            {
                continue;
            }
            if(sum + candidates[i] > target)
            {
                break;
            }
            aux.push_back(candidates[i]);
            backtracker(candidates, answer, aux, target, i+1, sum + candidates[i]);
            aux.pop_back();
        }

    }

// What if EVEN if the given set has duplicate values BUT we still don't want duplicate values in any of our combination sequences? Just change condition i > level to i > 0 and it'll happen!

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> answer;
        sort(candidates.begin(), candidates.end());

        vector<int> aux;

        backtracker(candidates, answer, aux, target, 0, 0);

        return answer;
    }

    void backtracker(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& aux, int target, int level, int sum)
    {
        if(sum == target || level == candidates.size())
        {
            if(sum == target)
            {
                answer.push_back(aux);
            }
            return;
        }

        for(int i = level; i < candidates.size(); i++)
        {
            if(i > 0 && candidates[i] == candidates[i-1])      // notice the change here!
            {
                continue;
            }
            if(sum + candidates[i] > target)
            {
                break;
            }
            aux.push_back(candidates[i]);
            backtracker(candidates, answer, aux, target, i+1, sum + candidates[i]);
            aux.pop_back();
        }

    }

