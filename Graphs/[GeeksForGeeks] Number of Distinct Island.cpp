namespace std {
    template <>
    struct hash<vector<pair<int, int>>> {
        size_t operator()(const vector<pair<int, int>>& v) const {
            size_t hash_val = 0;
            for (const auto& p : v) {
                hash_val ^= hash<int>()(p.first) + 0x9e3779b9 + (hash_val << 6) + (hash_val >> 2);
                hash_val ^= hash<int>()(p.second) + 0x9e3779b9 + (hash_val << 6) + (hash_val >> 2);
            }
            return hash_val;
        }
    };
}

class Solution 
{
  public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        unordered_set<vector<pair<int, int>>> shapes;
        int r = grid.size(), c = grid[0].size();
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                {
                    vector<pair<int, int>> shape;
                    DFS(grid, i, j, shape, i, j);
                    shapes.insert(shape);
                }
            }
        }
        
        
        return shapes.size();
    }
    
    void DFS(vector<vector<int>>& grid, int row, int col, vector<pair<int, int>>& shapes, int basex, int basey)
    {
        shapes.push_back({row-basex, col-basey});
        grid[row][col] = -1;
        
        if(row-1 >= 0 && grid[row-1][col] == 1)
        {
            DFS(grid, row-1, col, shapes, basex, basey);
        }
        if(col-1 >=0 && grid[row][col-1] == 1)
        {
            DFS(grid, row, col-1, shapes, basex, basey);
        }
        if(row+1 < grid.size() && grid[row+1][col] == 1)
        {
            DFS(grid, row+1, col, shapes, basex, basey);
        }
        if(col+1 < grid[0].size() && grid[row][col+1] == 1)
        {
            DFS(grid, row, col+1, shapes, basex, basey);
        }
    }
};
