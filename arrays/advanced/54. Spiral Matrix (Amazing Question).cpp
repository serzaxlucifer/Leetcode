// The Best Solution I could find (God its beautiful. Runtime: 0ms):

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> answer;
    // Direction Selection [Generalized Solution]

    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};       // {row, col} increment factor
    int directionSelector = 0;                                              // possible: 0, 1, 2, 3.

    int rowLimit = matrix.size();
    int colLimit = matrix[0].size();
    int curRow = 0;
    int curCol = -1;

    vector<int> bounds{colLimit, rowLimit-1};

    while(bounds[directionSelector % 2])
    {
        for(int i = 0; i < bounds[directionSelector % 2]; i++)
        {
            curRow += directions[directionSelector][0];
            curCol += directions[directionSelector][1];
            answer.emplace_back(matrix[curRow][curCol]);
        }
        bounds[directionSelector%2]--;
        directionSelector = (directionSelector + 1)%4;
    }

    return answer;
}

// Four Pointer Manipulation Approach:
vector<int> answer;
        // 4 Pointer Manipulation Approach

        int rowBegin = 0;
        int rowEnd = matrix.size()-1;
        int colBegin = 0;
        int colEnd = matrix[0].size()-1;

        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            for(int i = colBegin; i <= colEnd; i++)
            {
                answer.emplace_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            for(int i = rowBegin; i <= rowEnd; i++)
            {
                answer.emplace_back(matrix[i][colEnd]);
            }
            colEnd--;
            if(rowBegin <= rowEnd)
            {
            for(int i = colEnd; i >= colBegin; i--)
            {
                answer.emplace_back(matrix[rowEnd][i]);
            }
            
            rowEnd--;
            }
            if(colBegin <= colEnd)
            {
            for(int i = rowEnd; i >= rowBegin; i--)
            {
                answer.emplace_back(matrix[i][colBegin]);
            }
            colBegin++;
            }
        }

        return answer;
    }


