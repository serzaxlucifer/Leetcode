// First Approach (Achieving less space using boolean arrays):

// Time Complexity: O(n^2) and Space Complexity: O(n^2) {Big Oh Notation}   // Memory Test: Beats 98% solutions and 80% in runtime
bool isValidSudoku(vector<vector<char>>& board) {
        // using 3 flags for the three checking conditions.

        bool flag1[9][9] = {0};      // row contraint          ---  first index denotes row number, the next marks numbers used.
        bool flag2[9][9] = {0};      // column constraint      ---  first index denotes col number, the next marks numbers used.
        bool flag3[9][9] = {0};      // sub-box constraint     ---  first index denotes box number, the next marks numbers used.

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j]!='.')
                {
                    int mappedIndex = board[i][j] - '0' - 1;        // 1 maps to index 0, 2 to 1 and so on... till 9 to flag[x][8]
                    int subboxNumber = ((i/3)*3) + (j/3);
                    if(flag1[i][mappedIndex] || flag2[j][mappedIndex] || flag3[subboxNumber][mappedIndex])
                    {
                        return false;
                    }
                    // set the flags.
                    flag1[i][mappedIndex] = flag2[j][mappedIndex] = flag3[subboxNumber][mappedIndex] = true;
                }
            }
        }

        return true;
    }

// Further optimization:

// Can we use 1-D arrays for flagging? YES! Use the 0-8th bits in the integer range to mark flags. But this will require an int array[] which is space consuming! This solution will occupy much more space than above ones but runtime is expected to decrease as bitwise operators are really quick.

bool isValidSudoku(vector<vector<char>>& board) {
        // using 3 flags for the three checking conditions.

        int flag1[9] = {0};      // row contraint          
        int flag2[9] = {0};      // column constraint      
        int flag3[9] = {0};      // sub-box constraint   

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j]!='.')
                {
                    int mappedIndex = board[i][j] - '1';
                    int mask = 1 << mappedIndex;        
                    int subboxNumber = ((i/3)*3) + (j/3);

                    if((flag1[i] & mask) == mask || (flag2[j] & mask) == mask || (flag3[subboxNumber] & mask) == mask)
                    {
                        return false;
                    }
                    
                    flag1[i] |= mask;
                    flag2[j] |= mask;
                    flag3[subboxNumber] |= mask; 
                }
            }
        }

        return true;
    }

