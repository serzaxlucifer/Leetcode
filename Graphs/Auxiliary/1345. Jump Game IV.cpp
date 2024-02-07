    int minJumps(vector<int>& arr) 
    {
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < arr.size(); i++)
        {
            map[arr[i]].push_back(i);
        }
        int answer = 0;

        queue<int> BFS;
        vector<bool> visited(arr.size(), 0);
        BFS.push(0);
        visited[0] = true;

        while(!BFS.empty())
        {
            int size = BFS.size();

            for(int i = 0; i < size; i++)
            {
                int index = BFS.front(); BFS.pop();
                if(index == arr.size() - 1)
                {
                    return answer;
                }

                if(index - 1 >= 0 && visited[index-1] == 0)
                {
                    visited[index-1]= true;
                    BFS.push(index-1);
                }
                if(index + 1 < arr.size() && visited[index+1] == 0)
                {
                    visited[index+1]= true;
                    BFS.push(index+1);
                }
                vector<int>& equals = map[arr[index]];
                
                for(int i = 0; i < equals.size(); i++)
                {
                    if(!visited[equals[i]])
                    {
                        visited[equals[i]]= true;
                        BFS.push(equals[i]);
                    }
                }


                equals.clear();
            }
            answer++;
        }

        return 0;
    }
