vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int DIR[5] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> BFS;
        int r = mat.size(), c = mat[0].size();
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(mat[i][j])
                {
                    mat[i][j] = -1;
                }
                else
                {
                    BFS.push({i, j});
                }
            }
        }

        while(!BFS.empty())
        {
            int row = BFS.front().first, col = BFS.front().second;
            BFS.pop();

            for(int i = 0; i < 4; i++)
            {
                int nrow = row + DIR[i], ncol = col + DIR[i + 1];

                if(nrow < 0 || ncol < 0 || nrow == r || ncol == c || mat[nrow][ncol] != -1)
                {
                    continue;
                }

                mat[nrow][ncol] = mat[row][col] + 1;

                BFS.push({nrow, ncol});
            }

        }

        return mat;
    }
