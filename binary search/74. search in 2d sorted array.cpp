// my solution (beats 91%)

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size()-1;
        int arrayIndex = 0;

        int mid = start + (end-start)/2;
        while(start <= end)
        {
            if(matrix[mid][0] == target)
            {
                return true;
            }
            if(matrix[mid][0] > target)
            {
                end = mid - 1;
            }
            else if(mid != matrix.size()-1)
            {
                if(matrix[mid+1][0] > target)
                {
                    arrayIndex = mid;
                    break;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                arrayIndex = mid;
                break;
            }
            mid = start + (end-start)/2;
        }

        // Binary Search
        start = 0;
        end = matrix[arrayIndex].size()-1;
        mid = start + (end - start)/2;

        while(start <= end)
        {
            if(matrix[arrayIndex][mid] == target)
            {
                return true;
            }
            if(matrix[arrayIndex][mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }

        return false;
    }

// another solution (better maybe):

