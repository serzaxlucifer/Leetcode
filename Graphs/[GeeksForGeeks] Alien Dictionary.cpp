string findOrder(string dict[], int N, int K) 
    {
        string answer = "";
        if(N == 1)
        {
            return dict[0];
        }
        
        vector<vector<int>> graph(K, vector<int>());
        vector<int> inDegree(K, 0);
        vector<int> topoSort;
        
        for(int i = 0; i < N-1; i++)
        {
            int j = 0;
            while(dict[i][j] == dict[i+1][j] && dict[i][j] != '\0' && dict[i+1][j] != '\0')
            {
                j++;
            }
            
            if(dict[i][j] == '\0')
            {
                continue;
            }
            
            graph[dict[i][j]-97].push_back(dict[i+1][j] - 97);
            inDegree[dict[i+1][j] - 97]++;
        }
        
        // Do Topological sorting on the graph.
        
        queue<int> kahn;
        for(int i = 0; i < K; i++)
        {
            if(inDegree[i] == 0)
            {
                kahn.push(i);
            }
        }
        
        while(!kahn.empty())
        {
            int node = kahn.front();
            topoSort.push_back(node);
            kahn.pop();
            
            for(int it: graph[node])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                {
                    kahn.push(it);
                }
            }
        }

        
        for(int i = 0; i < K; i++)
        {
            answer += char(topoSort[i] + 97);
        }
        
        return answer;
        
    }
