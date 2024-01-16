class UnionFind
{

    public:
    int *parent, *rank, *size;
    UnionFind(int N)
    {
        parent = new int[N];
        rank = new int[N];
        size = new int[N];
        for(int i = 0; i < N; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
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
        if(size[i] > size[j])
        {
            parent[j] = i;
            size[i] += size[j];
        }
        else
        {
            parent[i] = j;
            size[j] += size[i];
        }
    }
};


class Solution {
public:

    bool isValid(int r, int c, int n)
    {
        return r >= 0 && c >= 0 && r < n && c < n;
    }

    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        UnionFind UF(n*n);

        // Dynamic Disjoint Set Union

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int identity = i*n + j;
                if(!grid[i][j])
                {
                    continue;
                }

                for(int k = 0; k < 4; k++)
                {
                    int I = i + dr[k];
                    int J = j + dc[k];

                    if(isValid(I, J, n) && grid[I][J] == 1)
                    {
                        int IDENTITY = I*n + J;
                        UF.connect(identity, IDENTITY);
                    }
                }
            }
        }

        int maxArea = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j])
                {
                    continue;
                }
                
                set<int> components;
                for(int k = 0; k < 4; k++)
                {
                    int I = i + dr[k], J = j + dc[k];
                    if(isValid(I, J, n) && grid[I][J])
                    {
                        components.insert(UF.find(I*n + J));
                    }
                }

                int size = 0;
                for(auto it : components)
                {
                    size += UF.size[it];
                }

                maxArea = max(maxArea, size+1);

            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) 
        {
            maxArea = max(maxArea, UF.size[UF.find(cellNo)]);
        }

        return maxArea;
    }
};
