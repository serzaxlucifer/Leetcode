// Recursive Bactracking:

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {

        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(backtracker(board, word, 0, i, j, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtracker(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited)
    {

        if(word[index] == board[x][y])
        {
            if(index+1 == word.length())
            {
                return true;
            }

                visited[x][y] = true;
                if(is_valid(visited, board, x+1, y))
                {
                    if(backtracker(board, word, index+1, x+1, y, visited))
                    {
                        return true;
                    }
                }
                if(is_valid(visited, board, x, y+1))
                {
                    if(backtracker(board, word, index+1, x, y+1, visited))
                    {
                        return true;
                    }
                }
                if(is_valid(visited, board, x-1, y))
                {
                    if(backtracker(board, word, index+1, x-1, y, visited))
                    {
                        return true;
                    }
                }
                if(is_valid(visited, board, x, y-1))
                {
                    if(backtracker(board, word, index+1, x, y-1, visited))
                    {
                        return true;
                    }
                }
                visited[x][y] = false;
        }

        return false;
    }

    bool is_valid(vector<vector<bool>>& visited, vector<vector<char>>& board, int x, int y)
    {
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
        {
            return false;
        }
        if(visited[x][y])
        {
            return false;
        }

        return true;
    }
};

// Better Solution (same logic):  // removing use of visited array

class Solution {
private:
    bool backtrack(vector<vector<char>>& board, int row, int col, string &word, int pos)
    {
        if(pos >= word.size()) return true;
        if(row < 0 || row>=board.size() || col<0 || col>=board[0].size()) return false;

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        if(board[row][col] != word[pos]) return false;
        board[row][col] = '0';    // SEE HOW WE'RE REMOVING USE OF VISITED ARRAY.
        for(int i=0; i<4; i++)
        {
            int x = row + dx[i], y = col + dy[i];
            if(backtrack(board, x, y, word, pos+1)) return true;
        }
        board[row][col] = word[pos];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            if(backtrack(board, i, j, word, 0)) return true;
        }
        return false;
    }
};

// Now, consider that the word to find is AAABS. Suppose we're finding AAA at places and then not going anywhere it wastes time.
// If we started from S then we could stop earlier. So consider this code:

bool exist(vector<vector<char>>& board, string word) 
    {
        int dirs[5] = {0, -1, 0, 1, 0};
        map<char,int> cnt;
        int m = board.size(), n = board[0].size(), l = word.size();
        
        for (char c : word) cnt[c] += 1;
        
        if (cnt[word[0]] > cnt[word[l-1]])
            reverse(word.begin(), word.end());
        
        function<bool(int,int,int)> dfs;
        dfs = [&] (int i, int j, int s) -> bool
        {
            if (s == l) return true;
            
            if (i < 0 or i >= m or j < 0 or j >= n) return false;
            if (board[i][j] != word[s])             return false;
            
            board[i][j] = '#';
            for (int d = 0; d < 4; ++d)
                if (dfs(i + dirs[d], j + dirs[d+1], s+1)) return true;
            board[i][j] = word[s];
            
            return false;
        };
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(i, j, 0)) return true;
        
        return false;
    }

// RUNTIME: 28ms!
// Another prelimanary check can be checking if the number of alphabets in the words are lesser than their frequency in the board. If not, you simply WONT find !

