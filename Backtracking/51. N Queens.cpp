/*
      Optimization in is_safe() function:

      The idea is not to check every element in the right and left diagonal, instead use the property of diagonals: 

      1) The sum of i and j is constant and unique for each right diagonal, where i is the row of elements and j is the 
      column of elements. 
      
      2) The difference between i and j is constant and unique for each left diagonal, where i and j are row and column of 
      element respectively.
*/

vector<vector<string>> solveNQueens(int n) 
    {   
        vector<vector<string>> answer;
        vector<int> aux(n+1, 0);
        string s = "";

        for(int i=0 ; i<n ; i++) 
        {
            s.push_back('.');
        }

        vector<string> temp(n,s);

        backtracker(n, answer, aux, 1, temp);

        return answer;
    }

    void backtracker(int n, vector<vector<string>>& answer, vector<int>& aux, int index, vector<string>& temp)
    {
        if(index > n)
        {
            answer.push_back(temp);

            return;
        }

        for(int i = 1; i < aux.size(); i++)
        {
            if(isSafe(aux, i, n, index))
            {
                aux[index] = i;
                temp[index-1][i-1] = 'Q';

                backtracker(n, answer, aux, index+1, temp);

                aux[index] = 0;
                temp[index-1][i-1] = '.';
            }
        }
    }

    bool isSafe(vector<int>& aux, int col, int n, int row)
    {
        for (int j = 1; j <= row-1; j++)
        {
            if (aux[j] == col || (abs(aux[j] - col) == abs(j - row)))
            {
                return false;
            }
        }
        return true;
    }
