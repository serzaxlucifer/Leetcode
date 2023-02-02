// Only one lucky number will exist at max.

vector<int> luckyNumbers (vector<vector<int>>& arr) {
        int m, n;
        m = arr.size();
        n = arr[0].size();
        
        vector < int >ans;
        for (int i = 0; i < m; ++i)
            {
            int minIdx = 0;
            for (int j = 0; j < n; ++j)
            {
            if (arr[i][j] < arr[i][minIdx])
                minIdx = j;
            }

            bool flag = true;
            for (int k = 0; k < m; ++k)
            {
            if (arr[k][minIdx] > arr[i][minIdx])
                {
                flag = false;
                break;
                }
            }

            if (flag)
            {
            ans.push_back (arr[i][minIdx]); 
            break;
            }
            
            }

        return ans;
    }
