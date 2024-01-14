// Striver (TakeUForward) Original Question

int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        if(start == end)
        {
            return 0;
        }
        
        vector<int> DIST(100000, 1e8);
        queue<pair<int, int>> BFS;
        BFS.push({start, 0});
        DIST[start] = 0;
        int runs = 0;
        
        while(!BFS.empty())
        {
            runs++;
            cout << runs << endl;
            int node = BFS.front().first;
            int steps= BFS.front().second;
            
            BFS.pop();
            
            for(int i : arr)
            {
                int newNode = i * node % 100000;
                if(steps + 1 < DIST[newNode])
                {
                    DIST[newNode] = steps + 1;
                    
                    if(newNode == end)
                    {
                        return steps + 1;
                    }
                    
                    BFS.push({newNode, steps + 1});
                    
                }
            }
        }
        
        
        return -1;
    }
