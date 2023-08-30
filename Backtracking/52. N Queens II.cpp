class Solution {
public:

    int arr[10] = {0};

    int totalNQueens(int n) 
    {
        return backtracker(1, n);
    }

    int backtracker(int index, int n)
    {
        if(index > n)
        {
            return 1;
        }

        int count = 0;

        for(int i = 1; i <= n ; i++)
        {
            if(isSafe(i, index))
            {
                arr[index] = i;

                count += backtracker(index + 1, n);

                arr[index] = 0;
            }
        }

        return count;
    }

    bool isSafe(int col, int row)
    {
        for (int j = 1; j <= row-1; j++)
        {
            if (arr[j] == col || (abs(arr[j] - col) == abs(j - row)))
            {
                return false;
            }
        }
        return true;
    }

};
