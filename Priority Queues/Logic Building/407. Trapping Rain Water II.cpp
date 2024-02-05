/*
        If you are thinking of converting the classic trapping rain water to this,
    then it might not work as expected. Lets say, for each position, you compute the
    horizontal blocking height and the vertical blocking height. Now that you know the
    blocking heights for all 4 dirs, you might think the volume computation from min of these
    blocking heights will give the answer, but it won't give optimal answer.
    
    Reason being, that we are not considering the case when any of the connecting horizontal or
    vertical blocks might have a way to drain the water.
    
    4 4 4 4
    4 3 3 4
    4 4 3 4,
    Here as we can see even though horizontal and vertical blocking height logic seems to give ans = 1 (at (1, 1) block), in reality
    it is 0. The block at (1, 2) will spill the water via (2, 2) and won't be able to hold any water, so the block at
    (1, 1) won't be able to hold any water as well no matter what.
    
    Now how do we find the solution ?
    What if we are able to find a way to approach a block via its min height blocking cell and then just check if the height of min block
    cell is greater than curr. If it is greater, then curr cell can hold water, this is because we were able to reach the current cell via
    the min height blocking cell and that means remaining blocking cells are all greater in height than this path cell. So if this path cell
    is greater than current, then all other blocking cells are greater as well.
    
    Now to actually do this in practice, we make use of min heap. We add the initial border cells to heap. Then slowly start reaching the inner
    cells via the shortest height boundary cells, while keeping track of tallest cell boundary in the path.
    Each time we reach an inner cell, there are 2 possibilities:
    1. Inner cell is greater, then we add this to heap as well. This can act as a blocking height for more inner cells.
    2. Inner cell is smaller, then we know that this inner call can hold water = path_cell - inner_cell. Add this to heap as well
    
    While adding new elements to heap, make sure to add the max height of that path, since that is the actual boundary in that path.
    
    TC: O(MNlog(MN))
    SC: O(MN)

*/

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
