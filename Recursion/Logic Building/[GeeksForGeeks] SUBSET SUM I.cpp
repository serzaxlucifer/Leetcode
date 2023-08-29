// A good and basic question!

vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> answer;
        
        backtracker(answer, arr, 0, 0);
        
        return answer;
    }
    
    void backtracker(vector<int>& answer, vector<int>& arr, int depth, int sum)
    {
        if(depth == arr.size())
        {
            answer.push_back(sum);
            return;
        }
        
        backtracker(answer, arr, depth+1, sum + arr[depth]);
        backtracker(answer, arr, depth+1, sum);
    }
