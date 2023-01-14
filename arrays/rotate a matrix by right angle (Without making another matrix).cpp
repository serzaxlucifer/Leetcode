void rotate(vector<vector<int>>& matrix) {
        int limit = matrix.size();
        for(int rows = 0; rows < (limit+1)/2; rows++)
        {
            for(int columns = 0; columns < limit/2; columns++)
            {
                int temp = matrix[rows][columns];
                matrix[rows][columns] = matrix[limit-1-columns][rows];
                matrix[limit-1-columns][rows] = matrix[limit-1-rows][limit-1-columns];
                matrix[limit-1-rows][limit-1-columns] = matrix[columns][limit-1-rows];
                matrix[columns][limit-1-rows] = temp;
            }
        }
    }
