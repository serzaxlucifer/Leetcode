// best solution 0ms
bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = 0;
        int columns = matrix[0].size() - 1;

        while(rows < matrix.size() && columns >= 0)
        {
            if(target == matrix[rows][columns])
            {
                return true;
            }
            if(target > matrix[rows][columns])
            {
                rows++;
            }
            else
            {
                columns--;
            }
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

