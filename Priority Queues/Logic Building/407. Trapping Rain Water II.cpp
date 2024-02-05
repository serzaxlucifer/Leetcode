    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int volume = 0;
        int X = heightMap.size();
        int Y = heightMap[0].size();

        int directions[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto comp = [&](const array<int, 3>& a, const array<int, 3>& b) { return a[0] >= b[0]; };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> minHeap(comp);
        vector<vector<bool>> visited(X, vector<bool>(Y, false));

        for(int i = 0; i < X; i++)
        {
            minHeap.push({heightMap[i][Y-1], i, Y-1});
            minHeap.push({heightMap[i][0], i, 0});
            visited[i][Y-1] = visited[i][0] = true;
        }

        for(int i = 0; i < Y; i++)
        {
            minHeap.push({heightMap[0][i], 0, i});
            minHeap.push({heightMap[X-1][i], X-1, i});
            visited[0][i] = visited[X-1][i] = true;
        }

        while(!minHeap.empty())
        {
            int height = minHeap.top()[0], row = minHeap.top()[1], col = minHeap.top()[2];
            minHeap.pop();

            for(auto dir: directions)
            {
                int newRow = row + dir[0], newCol = col + dir[1];

                if(newRow >= 1 && newRow < X-1 && newCol >= 1 && newCol < Y-1 && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = true;
                    if(heightMap[newRow][newCol] < height)
                    {
                        volume += height - heightMap[newRow][newCol];
                    }

                    minHeap.push({max(height, heightMap[newRow][newCol]), newRow, newCol});
                }
            }
        }

        return volume;

    }
