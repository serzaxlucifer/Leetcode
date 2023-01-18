vector<vector<int>> generate(int numRows) {
        // Generate a Pascal's Triangle.
        if(numRows == 0)
        {
            return {};
        }

        vector<vector<int>> answer;
        answer.push_back({1});

        for(int i = 1; i < numRows; i++)
        {
            vector<int> to_push;
            to_push.push_back(1);

            for(int j = 1; j < i; j++)
            {
                to_push.push_back(answer[i-1][j-1]+answer[i-1][j]);
            }

            to_push.push_back(1);

            answer.push_back(to_push);
        }


        return answer;
    }
