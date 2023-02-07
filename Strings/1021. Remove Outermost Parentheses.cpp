string removeOuterParentheses(string s) {       // [beats 100% solutions]
        string result;
        int count = 0;              // either use stack or a count variable.

        for(char c : s)
        {
            if(c == '(')
            {
                count++;
                if(count > 1)
                result += "(";
            }
            else
            {
                count--;
                if(count > 0)
                result += ")";
            }
        }

        return result;
    }
