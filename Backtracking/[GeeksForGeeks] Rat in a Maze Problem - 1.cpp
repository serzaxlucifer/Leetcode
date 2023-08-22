// Question Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

/*
    STATEMENT: Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat 
    can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix 
    represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

    
    Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
*/

// A challenging aim is how do we track re-visiting of an already visited cell? I think you most definitely will need to pass a 2D visit tracking array by value.

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        if(m[0][0] == 0 )
        {
            return {"-1"};
        }
        
        vector<string>answer;
        vector<vector<int>> visited = m;
        
        for(int i = 0; i < m.size(); i++)
        {
            for(int j = 0; j < m[0].size(); j++)
            {
                visited[i][j] = 0;
            }
        }
        
        // Call the backtracker here.
        string movement;
        
        deducePaths(0, 0, m, movement, answer, visited);
        
        if(answer.size() == 0)
        {
            return {"-1"};
        }
        
        return answer;
        
        
    }
    
    void deducePaths(int x, int y, vector<vector<int>>& m, string& movement, vector<string>& answer, vector<vector<int>> visited)
    {
        if(x < 0 || y < 0 || x >= m.size() || y >= m[0].size() || m[x][y] == 0 || visited[x][y] == 1)
        {
            // no further possible solution, prune it here!
            return;
        }
        
        if(x == m[0].size()-1 && y == m.size()-1)
        {
            // This is a solution!
            answer.push_back(movement);
            return;
        }
        
        // you are at a valid point, let's explore further! Explore in all directions except the opposite of the one you travelled.
        
        visited[x][y] = 1;
        
        movement += "D";
        deducePaths(x+1, y, m, movement, answer, visited);
        movement.pop_back();
        
        movement += "L";
        deducePaths(x, y-1, m, movement, answer, visited);
        movement.pop_back();
        
        movement += "R";
        deducePaths(x, y+1, m, movement, answer, visited);
        movement.pop_back();
        
        movement += "U";
        deducePaths(x-1, y, m, movement, answer, visited);
        movement.pop_back();
    }
    
};
