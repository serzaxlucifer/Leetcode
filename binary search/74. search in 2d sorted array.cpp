// my initial solution (beats 50%)

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

// another solution (BEST): -- This is how you code, dude.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int start=0;
        int end=n*m-1;

        int mid=start+(end-start)/2;

        while(start<=end){
            int element=matrix[mid/m][mid%m];

            if(element==target){
                return 1;
            }

            if(element<target){
                start=mid+1;
            }

            else{
                end=mid-1;
            }

            mid=start+(end-start)/2;
        }

        return 0;

    }

// another solution:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows(matrix.size()), cols(matrix[0].size());
        int left(0), right(rows * cols);
        while(left < right)
        {
            const int mid = (left + right)/2, i = mid / cols, j = mid % cols;
            if (matrix[i][j] == target) return true;
            matrix[i][j] < target ? left = mid + 1 : right = mid;
        }
        return false;
    }

// mine improvised:
bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int outerSize = matrix.size();
        int innerSize = matrix[0].size();

        int start = 0;
        int end = outerSize*innerSize-1;
        int mid = start + (end - start)/2;

        while(start <= end)
        {
            if(matrix[mid/innerSize][mid%innerSize] == target)
            {
                return true;
            }
            else if(matrix[mid/innerSize][mid%innerSize] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return false;
    }

