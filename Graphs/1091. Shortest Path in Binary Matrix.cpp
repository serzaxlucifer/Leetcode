int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0])
        {
            return -1;
        }

        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), 1e9));
        queue<pair<int, pair<int, int>>> BFS;
        distance[0][0] = 0;
        BFS.push({0, {0, 0}});
        int m = grid.size();
        int n = grid[0].size();

        if(m == 1 && n == 1)
        {
            return 1;
        }

        int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        int dy[8] = {1, -1, 1, -1, 0, 0, -1, 1};

        while(!BFS.empty())
        {
            auto it = (BFS.front());
            int dist = it.first;
            int x = it.second.first;
            int y = it.second.second;

            BFS.pop();

            for(int i = 0; i < 8; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0 && dist + 1 < distance[nx][ny])
                {
                    distance[nx][ny] = dist + 1;
                    if(nx == m-1 && ny == n-1)
                    {
                        return distance[nx][ny]+1;
                    }
                    BFS.push({1 + dist, {nx, ny}});
                }
            }
        }


        return -1;

    }

// Even better

class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, int i, int j, int n, vector<vector<bool>>& visited){
        
        return (i>=0 and i<n and j>=0 and j<n and grid[i][j]==0 and !visited[i][j]);
        
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<pair<int, int>> q;
        int ans = 0;
        int nodesPushed;
        
        if(grid[0][0] == 0){
            q.push({0, 0});
            visited[0][0] = true;
        }
                
        while(!q.empty()){
            
            nodesPushed = q.size();
            ans++;
            
            for(int cnt = 0; cnt < nodesPushed; cnt++){
                
                pair<int, int> frontNode = q.front();
                q.pop();
            
                int i = frontNode.first, j = frontNode.second;

                if(i==n-1 and j==n-1) return ans;

                for(int k = i - 1; k <= i + 1 ; k++){
                    for(int l = j - 1; l <= j + 1; l++){
                        if(isValid(grid, k, l, n, visited)){
                            q.push({k, l});
                            visited[k][l] = true;
                        }
                    }
                }                
                
            }            
            
        }
        
        return -1;
        
    }
};

// Best Approach:

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0 or grid.back().back() != 0) return -1;

        int n = grid.size();
        if (n == 1) return 1;

        int res = 1;
        int q[100000]; 
        int start = 0, end = 1; 
        q[0] = (0 << 16) | 0;
        grid[0][0] = 1;

        while (start < end) {
            int newEnd = end; // Track where the next segment ends

            for (int i = start; i < end; ++i) {
                int x = q[i] >> 16; // Extract x
                int y = q[i] & 0xFFFF; // Extract y

                if (x == n - 1 && y == n - 1) return res;

                for (int j = 0; j < 8; ++j) {
                    int x_new = x + dirs[j][0];
                    int y_new = y + dirs[j][1];

                    if (x_new >= 0 && x_new < n && y_new >= 0 && y_new < n && grid[x_new][y_new] == 0) {
                        grid[x_new][y_new] = 1;
                        q[newEnd++] = (x_new << 16) | y_new;
                    }
                }
            }

            start = end;
            end = newEnd;
            ++res;
        }

        return -1;
    }
