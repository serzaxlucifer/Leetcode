    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int size = matrix[0].size();
        vector<int> height(size, 0);
        vector<int> left(size, 0);
        vector<int> right(size, size);

        int maxArea = 0;

        for(int i = 0; i < matrix.size(); i++)          // process row by row
        {
            int rightBoundary = size, leftBoundary = 0;

            for(int j = size - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                {
                    right[j] = min(right[j], rightBoundary);
                }
                else
                {
                    right[j] = size;
                    rightBoundary = j;
                }
            }

            for(int j = 0; j < size; j++)
            {
                if(matrix[i][j] == '1')
                {
                    left[j] = max(left[j], leftBoundary);
                    height[j]++;
                    maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
                }
                else
                {
                    left[j] = 0;
                    leftBoundary = j + 1;
                    height[j] = 0;
                }
            }
        }

        return maxArea;
    }
