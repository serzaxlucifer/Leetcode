// This problem shows us how to best optimize space complexity! When there is no way to distinguish when the changes made in iterations alter results of previous iterations, change only the part that has already been iterated with some sort of flag, then reprocess and process as if the iterations are not affected at all!

// A classic example!

// 2D MATRIX SETTING TO ZERO

 void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;

        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
            {
                isCol = true;
            }
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    // mark just beginnings.
                    matrix[0][j] = 0;   // already processed
                    matrix[i][0] = 0;   // already processed
                }
            }
        }

        // now do the remaining work.
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) 
        {
            for (int j = 0; j < matrix[0].size(); j++) 
            {
                matrix[0][j] = 0;
            }
        }

        if(isCol)
        {
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }

// another solution:

void setZeroes(vector<vector<int>>& matrix) {
         
    int rows = matrix.size(), cols = matrix[0].size();
  vector < int > row(rows,-1), col(cols,-1);
  


     for(int i=0;i<rows;i++)
     {
         for(int j=0;j<cols;j++){
             if(matrix[i][j]==0)
             {
                 row[i]=1;
                 col[j]=1;
             }
         }
     }

     for(int i=0;i<rows;i++)
     {
         for(int j=0;j<cols;j++){

             if(row[i]==1 || col[j]==1)
             matrix[i][j]=0;
         }


    }


    }
