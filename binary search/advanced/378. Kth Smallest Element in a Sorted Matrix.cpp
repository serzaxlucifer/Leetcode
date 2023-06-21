// An amazing explanation of the same (with visuals!) can be found at 
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1322101/c-java-python-maxheap-minheap-binary-search-picture-explain-clean-concise/

int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        // Utilizing Binary Search

        int rowLimit = matrix.size();
        int colLimit = matrix[0].size();

        int start = matrix[0][0];
        int end = matrix[rowLimit - 1][colLimit - 1];
        int ans = 0;

        while(start <= end)
        {
            int mid = (start + end) >> 1;

            if(countOfLess(matrix, rowLimit, colLimit, mid) >= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }

    int countOfLess(vector<vector<int>>& matrix, int rL, int cL, int key)
    {
        // Efficiently find the number of elements 'SMALLER' than key.

        int i = 0;
        int j = cL - 1;

        int count = 0;

        while(i < rL && j >= 0)        // improvised loop.
        {
            if(matrix[i][j] <= key)
            {
                i++;
                count += (j+1);
            }
            else
            {
                j--;
            }
        }

        /*  Original Loop:

        for(i = 0; i < rL; i++)
        {
            while(j >= 0 && matrix[i][j] > key)
            {
                j--;
            }

            count += (j+1);
        }
        */

        return count;
    }
