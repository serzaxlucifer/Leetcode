// row, col solution:

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(0);
        int start = 0;
        int rLimit = matrix.size();
        int cLimit = matrix[0].size();
        int end = cLimit - 1;

        while(start < rLimit && end >= 0)
        {
            int element = matrix[start][end];
            if(element == target)
            {
                matrix.clear();
                return true;
            }
            else if(element < target)
            {
                start++;
            }
            else
            {
                end--;
            }

        }
        matrix.clear();

        return false;
    }





