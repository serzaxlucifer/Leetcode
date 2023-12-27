vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        queue<int> BFS;
        vector<int> inDegree(numCourses);
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> topoSort;

        for(int i = 0; i < prerequisites.size(); i++)
        {
            inDegree[prerequisites[i][0]]++;
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(inDegree[i] == 0)
            {
                BFS.push(i);
            }
        }

        while(!BFS.empty())
        {
            int node = BFS.front(); BFS.pop();
            topoSort.push_back(node);

            for(int i : adjList[node])
            {
                inDegree[i]--;
                if(inDegree[i] == 0)
                {
                    BFS.push(i);
                }
            }
        }

        if(numCourses == topoSort.size())
        {
            return topoSort;
        }

        return {};
    }
