int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        if(matrix.size() == 1)
        {
            return matrix[0][0];
        }

        int answer = INT_MAX;

        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                int one = INT_MAX, two = INT_MAX, three = INT_MAX;

                if(j - 1 >= 0)
                {
                    one = matrix[i-1][j-1];
                } 

                if(j + 1 < matrix.size())
                {
                    two = matrix[i-1][j+1];
                }

                three = matrix[i-1][j];

                matrix[i][j] += min({one, two, three});

                if(i == matrix.size() - 1)
                {
                    answer = (answer <= matrix[i][j] ? answer : matrix[i][j]);
                }
            }
        }

        return answer;
    }
