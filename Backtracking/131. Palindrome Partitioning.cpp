vector<vector<string>> partition(string s) 
    {
        vector<vector<bool>> dp (s.length(), vector <bool> (s.length(), false));
        vector<vector<string>> answer;
        vector<string> aux;

        backtracker(s, answer, aux, 0, dp);

        return answer;

    }

    void backtracker(string& s, vector<vector<string>>& answer, vector<string>& aux, int start, vector<vector<bool>>& dp)
    {
        if(start >= s.length())
        {
            answer.push_back(aux);
            return;
        }

        for(int i = start; i < s.length(); i++)
        {
            if(s[start] == s[i] && (i - start <= 2 || dp[start + 1][i - 1]))
            {
                dp[start][i] = true;
                aux.push_back(s.substr(start, i - start + 1));
                backtracker(s, answer, aux, i + 1, dp);
                aux.pop_back();
            }
        }
    }
