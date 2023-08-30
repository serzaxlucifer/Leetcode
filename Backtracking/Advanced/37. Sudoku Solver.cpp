// Backtracking!

void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(is_Valid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if(solve(board))
                            {
                                return true;
                            }

                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    bool is_Valid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == c)
            {
                return false;
            }

            if(board[i][col] == c)
            {
                return false;
            }

            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c)
            {
                return false;
            }
        }

        return true;
    }

// Can we further optimize? Analyze the code time and space wise. Are we effectively using space for best
// time tradeoff? Are there recomputational loopholes??

// To begin this, we see that the for loop needs to track with useless iterations where we left before previous call
// can we rather pass parameters for it to know where to pick up? The DFS solution described below counters it
// effectively. Look at its algorithmic and memory design. It frees up the time consumed by is_valid()
// to constant O(1) true time. It's a much better design.

// DFS-Based Solution: (Seems to work much faster!)

class Solution {
public:
    // THIS IS NOT MY ORIGINAL SOLUTION AND CREDIT BELONGS TO LEETCODE AND ITS USERBASE.
    
    bool col[9][9], row[9][9], cube[3][3][9];
    int n, m;

    bool dfs(int x, int y, vector<vector<char>>& board) 
    {
        if (y == 9) y = 0, x++;
        if (x == 9) return true;
        if (board[x][y] != '.') return dfs(x, y + 1, board);
        
        for (int i = 0; i < 9; i++) 
        {
            if (!col[x][i] && !row[y][i] && !cube[x / 3][y / 3][i]) 
            {
                col[x][i] = row[y][i] = cube[x / 3][y / 3][i] = true;
                board[x][y] = i + '1';
                if (dfs(x, y + 1, board)) 
                  return true;
                board[x][y] = '.';
                col[x][i] = row[y][i] = cube[x / 3][y / 3][i] = false;
            }
        }
        
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(col, 0, sizeof col);
        memset(row, 0, sizeof col);
        memset(cube, 0, sizeof col);

        n = board.size(), m = board[0].size();
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '1'; // ‘0’
                    // cout << val << endl;
                    col[i][val] = row[j][val] = cube[i/3][j/3][val] = true;
                }
            }
        }
        
        dfs(0, 0, board);
        
        
    }
};

// So, let's instead decipher this approach and understand it and well, clean up this messy code!
