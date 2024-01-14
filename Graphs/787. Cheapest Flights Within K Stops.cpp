int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k)
                continue;

            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;

                if (cost + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
            
        return dist[dst];
    }

// OR

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<int> c(n, 1e8);
        c[src] = 0;
        
        for(int z=0; z<=k; z++)
        {
            vector<int> C(c);
            for(auto e: flights)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }

        return c[dst] == 1e8 ? -1 : c[dst];
    }
