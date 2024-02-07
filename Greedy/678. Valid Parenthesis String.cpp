// This question leaves me wanting to leave this thing... I mean what am I doing? :(

// Here you go, the editorial does fine at explanation:  https://leetcode.com/problems/valid-parenthesis-string/editorial/


    bool checkValidString(string s) 
    {
        int lowerBound = 0;
        int higherBound = 0;

        for(char a : s)
        {
            lowerBound += a == '(' ? 1 : -1;
            higherBound += a != ')' ? 1 : -1;
            if(higherBound < 0)
            {
                return false;
            }
            if(lowerBound < 0)
            {
                lowerBound = 0;
            }
        }

        return lowerBound == 0;
    }
