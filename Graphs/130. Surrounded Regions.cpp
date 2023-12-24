class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int r = board.size(), c = board[0].size();
        
        for(int i = 0; i < r; i++)
        {
            DFS(board, i, 0, r, c);
            DFS(board, i, c-1, r, c);
        }
        for(int i = 0; i < c; i++)
        {
            DFS(board, 0, i, r, c);
            DFS(board, r-1, i, r, c);
        }

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void DFS(vector<vector<char>>& board, int r, int c, int m, int n)
    {
        if(board[r][c] == 'O')
        {
            board[r][c] = '#';
            if(r-1 > 0)
            {
                DFS(board, r-1, c, m, n);
            }
            if(c-1 > 0)
            {
                DFS(board, r, c-1, m, n);
            }
            if(r+1 < m)
            {
                DFS(board, r+1, c, m, n);
            }
            if(c+1 < n)
            {
                DFS(board, r, c+1, m, n);

            }
        }
    }
};

// UNION FIND:

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
    void solve(vector<vector<char>>& board) 
    {
        int r = board.size(), c = board[0].size();
        if(r == 0 || c == 0)
        {
            return;
        }

        UnionFind UF = UnionFind(r*c+1);

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if((i == 0 || i == r - 1 || j == 0 || j == c - 1) && board[i][j] == 'O')
                {
                    UF.connect(c*i + j, r*c);
                }
                else if(board[i][j] == 'O')
                {
                    if(board[i - 1][j] == 'O')
                        UF.connect(i * c + j, (i - 1) * c + j);
                    if(board[i + 1][j] == 'O')
                        UF.connect(i * c + j, (i + 1) * c + j);
                    if(board[i][j - 1] == 'O')
                        UF.connect(i * c + j, i * c + j - 1);
                    if(board[i][j + 1] == 'O')
                        UF.connect(i * c + j, i * c + j + 1);
                }
            }
        }

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(!UF.connected(i*c + j, r*c))
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

};
