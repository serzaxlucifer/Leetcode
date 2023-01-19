// Code:

// amazing question: make a row then make next row in same array and keep doing it until you get the desired row.

vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex+1, 0);
        answer[0] = 1;

        for(int i = 1; i <= rowIndex; i++)          // generating rows
        {
            for(int j = i; j >= 1; j--)
            {
                answer[j] += answer[j-1];
            }
        }
        return answer;
    }

