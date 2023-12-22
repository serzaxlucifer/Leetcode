vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int pixelValue = image[sr][sc];
        if(pixelValue == color)
        {
            return image;
        }

        queue<pair<int, int>> BFS;
        int n = image[0].size(), m = image.size();

        BFS.push({sr, sc});
        image[sr][sc] = color;

        while(!BFS.empty())
        {
            int a = BFS.front().first, b = BFS.front().second;
            BFS.pop();

            if(a - 1 >= 0 && image[a - 1][b] == pixelValue)
            {
                image[a - 1][b] = color; BFS.push({a - 1, b});
            }
            if(b - 1 >= 0 && image[a][b - 1] == pixelValue)
            {
                image[a][b - 1] = color; BFS.push({a, b - 1});
            }
            if(a + 1 < m && image[a + 1][b] == pixelValue)
            {
                image[a + 1][b] = color; BFS.push({a + 1, b});
            }
            if(b + 1 < n && image[a][b + 1] == pixelValue)
            {
                image[a][b + 1] = color; BFS.push({a, b + 1});
            }
        }

        return image;
    }
