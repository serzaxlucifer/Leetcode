vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int size = graph.size();
        vector<bool> SOLUTION(size, false);
        vector<bool> visited(size, false);
        vector<bool> pathVisited(size, false);
        vector<int> ANSWER;

        for(int i = 0; i < size; i++)
        {
            if(!visited[i])
            {
                DFSexplorer(graph, i, SOLUTION, visited, pathVisited);
            }
        }

        for(int i = 0; i < size; i++)
        {
            if(SOLUTION[i])
            {
                ANSWER.push_back(i);
            }
        }

        return ANSWER;
    }

    bool DFSexplorer(vector<vector<int>>& graph, int node, vector<bool>& SOLUTION, vector<bool>& visited, vector<bool>& pathVisited)
    {
        visited[node] = pathVisited[node] = true;

        for(int i : graph[node])
        {
            if(!visited[i])
            {
                if(DFSexplorer(graph, i, SOLUTION, visited, pathVisited) == true)
                {
                    SOLUTION[node] = false;
                    return true;
                }
            }
            else if(pathVisited[i])
            {
                SOLUTION[node] = false;
                return true;
            }
        }

        SOLUTION[node] = true;
        pathVisited[node] = false;
        return false;
    }
