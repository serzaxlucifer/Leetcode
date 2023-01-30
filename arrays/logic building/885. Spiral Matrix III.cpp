// Brute Force (Absolute Brute) [Runtime: 15mS, beats 87% but solutions exist in 3 ms SO WE NEED TO WORK!]
// I'll optimize it!!!!!

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int toCover = rows*cols;

        // Now we just need to simulate the movement.
        vector<vector<int>> answer;

        int bounds[2] = {1, 1};
        int directionSelector = 0;
        int directions[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int curRow = rStart;
        int curCol = cStart;

        while(toCover)
        {
            for(int i = 0; i < bounds[directionSelector%2]; i++)
            {
                if(curRow >= 0 && curRow < rows && curCol < cols && curCol >=0)
                {
                    answer.push_back({curRow, curCol});
                    toCover--;
                }
                curRow += directions[directionSelector][0];
                curCol += directions[directionSelector][1];
            }

            bounds[directionSelector%2]++;
            directionSelector = (directionSelector+1)%4;
        }

        return answer;
    }

// 

// now we optimize! Well not much but we can optimize the space in above solution even further thus producing an even superior solution and the computations and lines of code are also reduced much more in this one thus also improving runtime!

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int toCover = rows*cols;

        // Now we just need to simulate the movement.
        vector<vector<int>> answer = {{rStart, cStart}};
        int dx = 0, dy = 1, temp;                                 // row and col increment factor.

        for(int i = 0; answer.size() < toCover; i++)
        {
            for(int j = 0; j < (i/2)+1; j++)
            {
                rStart += dx;
                cStart += dy;
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                   answer.push_back({rStart, cStart}); 
                }
            }
            temp = dx;
            dx = dy;
            dy = -temp;
        }

        return answer;
    }
