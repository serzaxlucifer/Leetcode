// Union Find (very Slow)

class UnionFind
{
    private:
    int *parent, *rank;

    public:
    UnionFind(int N)
    {
        parent = new int[N];
        rank = new int[N];
        for(int i = 0; i < N; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~UnionFind()
    {
        delete [] parent;
        delete [] rank;
    }

    int find(int p)
    {
        if(p == parent[p])
        {
            return p;
        }
        return parent[p] = find(parent[p]);
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    void connect(int p, int q)
    {
        int i = find(p);
        int j = find(q);

        if(i == j)
        {
            return;
        }
        if(rank[i] > rank[j])
        {
            parent[j] = i;
        }
        else if(rank[j] > rank[i])
        {
            parent[i] = j;
        }
        else
        {
            parent[i] = j;
            rank[j]++;
        }
    }
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size();
        if(r == 0 || c == 0)
        {
            return 0;
        }

        UnionFind UF = UnionFind(r*c+1);

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if((i == 0 || i == r - 1 || j == 0 || j == c - 1) && grid[i][j] == 1)
                {
                    UF.connect(c*i + j, r*c);
                }
                else if(grid[i][j] == 1)
                {
                    if(grid[i - 1][j] == 1)
                        UF.connect(i * c + j, (i - 1) * c + j);
                    if(grid[i + 1][j] == 1)
                        UF.connect(i * c + j, (i + 1) * c + j);
                    if(grid[i][j - 1] == 1)
                        UF.connect(i * c + j, i * c + j - 1);
                    if(grid[i][j + 1] == 1)
                        UF.connect(i * c + j, i * c + j + 1);
                }
            }
        }

        int answer = 0;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1 && !UF.connected(i*c + j, r*c))
                {
                    answer++;
                }
            }
        }

        return answer;
    }
};

// Boundary, multi-source DFS:

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size();
        
        for(int i = 0; i < r; i++)
        {
            DFS(grid, i, 0, r, c);
            DFS(grid, i, c-1, r, c);
        }
        for(int i = 0; i < c; i++)
        {
            DFS(grid, 0, i, r, c);
            DFS(grid, r-1, i, r, c);
        }

        int answer = 0;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                {
                    answer++;
                }
            }
        }

        return answer;
    }

    void DFS(vector<vector<int>>& grid, int r, int c, int m, int n)
    {
        if(grid[r][c] == 1)
        {
            grid[r][c] = -1;
            if(r-1 > 0)
            {
                DFS(grid, r-1, c, m, n);
            }
            if(c-1 > 0)
            {
                DFS(grid, r, c-1, m, n);
            }
            if(r+1 < m)
            {
                DFS(grid, r+1, c, m, n);
            }
            if(c+1 < n)
            {
                DFS(grid, r, c+1, m, n);

            }
        }
    }
};
