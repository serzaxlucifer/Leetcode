// My 1st Solution (involves Backtracking): [took help from editorial] (100% runtime)

vector<string> generateParenthesis(int n) {

        // Backtracking solution

        vector<string> answer;
        backtracking(answer, n, 0, 0, "");
        return answer;
    }

    void backtracking(vector<string>& answer, int n, int left, int right, string currentStr)
    {
        if(currentStr.length() == 2*n)
        {
            answer.emplace_back(currentStr);
            return;
        }

        if(left < n)
        {
            // you can add another '(' to generate a valid combination.
            backtracking(answer, n, left + 1, right, currentStr + "(");
        }

        if(right < left)
        {
            backtracking(answer, n, left, right + 1, currentStr + ")");
        }
    }

// What other optimizations? or approaches?
// Divide and Conquer, it seems according to the editorial. But what are the smaller subproblems? Obviously, it can only be strings of smaller length! I don't know why I am exclaiming!

// Read from editorial, too complex for me to understand!

