// My Brute Force Implementation: [A basic way of solving Matrix questions: Map input to 1-D traversal container/data structure.]

 vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c != mat.size()*mat[0].size())         // illegal reshaping, no. of matrix cells must be same. 
        {
            return mat;
        }

        vector<vector<int>> result;
        int rowLimit = mat.size();
        int colLimit = mat[0].size();
        vector<int> arr(r*c);

        // Map to 1-D Array.      
        for(int i = 0; i < rowLimit; i++)
        {
            for(int j = 0; j < colLimit; j++)
            {
                arr[i*colLimit + j] = mat[i][j];
            }
        }  
        int reader = 0;

        // now fill result!

        for(int i = 0; i < r; i++)
        {
            vector<int> temp;
            for(int j = 0; j < c; j++)
            {
                temp.emplace_back(arr[reader++]);
            }
            result.push_back(temp);
        }

        return result;
    }

// Now let's talk optimizations! Of course, above solution is NOT a very good approach. Its complex, both space and time wise.
// Let's try to remove all the extra space and try to simulate the problem statement in a single loop. Of course, the mapping will be complex so get ready with a paper!

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c != mat.size()*mat[0].size())         // illegal reshaping
        {
            return mat;
        }

        vector<vector<int>> result(r, vector<int>(c, 0));
        int rowLimit = mat.size();
        int colLimit = mat[0].size();
        
        for(int i = 0; i < r*c; i++)
        {
            result[i/c][i%c] = mat[i/colLimit][i%colLimit];         // BEST POSSIBLE COMPUTATION FOR THIS PROBLEM!
        }

        return result;
    }

