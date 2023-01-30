// my First Approach (using logic of Spiral Matrix I): [Based on Simulation Logic]

vector<vector<int>> generateMatrix(int n) {
        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};       // {column, row} increment factors.
        int row = 0;
        int column = -1;
        vector<vector<int>> answer(n, vector<int>(n, 0));
        int filler = 1;

        // now i need to fill it up!
        
        int bound[2] = {n, n-1};                                        // Col, Row Bound format
        int directionSelector = 0;                                      // possible values: 0, 1, 2, 3 mapping to directions 2D array.

        while(bound[directionSelector%2])
        {
            // do this!
            for(int i = 0; i < bound[directionSelector%2]; i++)
            {
                row += directions[directionSelector][1];
                column += directions[directionSelector][0];

                answer[row][column] = filler;
                filler++;
            }

            bound[directionSelector%2]--;
            directionSelector = (directionSelector+1)%4;
        }

        return answer;
        
    }

// We can also do it using multiple loops.
vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if (n < 1) {
            return res;
        }

        res = vector<vector<int>>(n, vector<int>(n, 0));

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int cnt = 1;

        while (cnt <= n * n) {
            // top;
            for (int i = left; i <= right; ++i) {
                res[top][i] = cnt++;
            }

            if (cnt > n * n) {
                break;
            }

            // right
            for (int i = top + 1; i < bottom; ++i) {
                res[i][right] = cnt++;
            }

            // bottom
            for (int i = right; i >= left; --i) {
                res[bottom][i] = cnt++;
            }

            // left
            for (int i = bottom - 1; i > top; --i) {
                res[i][left] = cnt++;
            }

            ++ left;
            -- right;
            ++ top;
            -- bottom;
        }
        return res;
    }

