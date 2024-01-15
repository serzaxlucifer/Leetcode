int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // DIJKSTRA ALGORITHM

        vector<pair<int,int>> adjList[n];
        for(auto it: times)
        {
            adjList[it[0]-1].push_back({it[1]-1, it[2]});
        }

        vector<int> DISTANCE(n, 1e8);
        DISTANCE[k-1] = 0;

        queue<pair<int,int>> DIJK;
        DIJK.push({k-1, 0});

        while(!DIJK.empty())
        {
            int node = DIJK.front().first;
            int time = DIJK.front().second;
            DIJK.pop();

            if (time > DISTANCE[node]) {
                continue;
            }

            for(auto it : adjList[node])
            {
                int newNode = it.first;
                int newTime = it.second + time;

                if(newTime < DISTANCE[newNode])
                {
                    DISTANCE[newNode] = newTime;
                    DIJK.push({newNode, newTime});
                }
            }
        }

        int time = 0;

        for(int i : DISTANCE)
        {
            if(i > time)
            {
                time = i;
            }
            if(i == 1e8)
            {
                time = -1;
                break;
            }
        }

        return time;
    }
