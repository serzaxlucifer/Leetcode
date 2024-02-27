class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int score = 0;
        int layers = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                layers++;
            }
            else
            {
                layers--;
            }

            if(s[i] == ')' && s[i-1] == '(')
            {
                score += 1 << layers;
            }
        }    

        return score;
    }
};
