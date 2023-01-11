bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool rotation[4];

        memset(rotation, true, sizeof(rotation));      // say all rotations will do it!
        int length = mat.size();

        for(int i = 0; i < length; i++)
        {
            for(int j = 0; j < length; j++)
            {
                if(mat[i][j] != target[i][j]) rotation[0] = false;
                if(mat[j][length-i-1] != target[i][j]) rotation[1] = false;
                if(mat[length-j-1][i] != target[i][j]) rotation[2] = false;
                if(mat[length-i-1][length-j-1] != target[i][j]) rotation[3] = false;
            if(!rotation[0] && !rotation[1] && !rotation[2] && !rotation[3])
            {
                return false;
            }
            }
        }

        return rotation[0] || rotation[1] || rotation[2] || rotation[3];
    }
