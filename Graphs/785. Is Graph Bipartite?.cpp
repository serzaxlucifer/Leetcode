bool isBipartite(vector<vector<int>>& graph) 
    {
        int nodes = graph.size();
        vector<int> visited(nodes, 0);

        for(int i = 0; i < nodes; i++)
        {
            if(!visited[i])
            {
                queue<pair<int, int>> BFS;
                BFS.push({i, 1});
                visited[i] = 1;

                while(!BFS.empty())
                {
                    int node = BFS.front().first;
                    int testCol = BFS.front().second;
                    BFS.pop();

                    for(int j = 0; j < graph[node].size(); j++)
                    {
                        if(visited[graph[node][j]] == testCol)
                        {
                            return false;
                        }
                        if(visited[graph[node][j]] == 0)
                        {
                            visited[graph[node][j]] = -testCol;
                            BFS.push({graph[node][j], -testCol});
                        }
                    }
                }
            }
        }

        return true;
    }
