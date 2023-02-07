// My First Implementation:[Runtime beating 65%]

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if(size != m*n) return {};

        // otherwise proceed further.
        int reader = 0;
        vector<vector<int>> result(m, vector<int>(n, 0));
        int count = m*n;

        while(reader < count)
        {
            result[reader/n][reader%n] = original[reader];
            reader++;
        }

        return result;
    }

// Another Solution:  [78%]

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if(size != m*n) return {};

        // otherwise proceed further.
        int reader = 0;
        vector<vector<int>> result;

        for(int i = 0; i < m; i++)
        {
            vector<int> temp;
            for(int j = 0; j < n; j++)
            {
                temp.emplace_back(original[reader++]);
            }
            result.emplace_back(temp);
        }

        return result;
    }

