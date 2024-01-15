int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        // Floyd Warshall Algorithm

        vector<vector<int>> WARSHALL(n, vector<int>(n, 1e8));
        for(auto it: edges)
        {
            WARSHALL[it[0]][it[1]] = it[2];
            WARSHALL[it[1]][it[0]] = it[2];
        }
        for(int i = 0; i < n; i++)
        {
            WARSHALL[i][i] = 0;
        }

        for(int via = 0; via < n; via++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(WARSHALL[i][via] == 1e8 || WARSHALL[via][j] == 1e8)
                    {
                        continue;   
                    }
                    WARSHALL[i][j] = min(WARSHALL[i][j], WARSHALL[i][via] + WARSHALL[via][j]);
                }
            }
        }

        int cityCount = 1e8;
        int cityNo = -1;

        for(int i = 0; i < n; i++)
        {
            int city = 0;
            for(int j = 0; j < n; j++)
            {
                if(WARSHALL[i][j] <= distanceThreshold)
                {
                    city++;
                }
            }

            if(cityCount >= city)
            {
                cityNo = i;
                cityCount = city;
            }
        }

        return cityNo;
    }
