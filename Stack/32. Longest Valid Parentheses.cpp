    int longestValidParentheses(string s) 
    {
        // Stack Solution:

        stack<int> matcher;
        int strLength = s.length();

        for(int i = 0; i < strLength; i++)
        {
            if(s[i] == '(')
            {
                matcher.push(i);
            }
            else
            {
                if(!matcher.empty())
                {
                    if(s[matcher.top()] == '(')
                    {
                        matcher.pop();
                    }
                    else
                    {
                        matcher.push(i);
                    }
                }
                else
                {
                    matcher.push(i);
                }
            }
        }

        if(matcher.empty())
        {
            return strLength;
        }

        int longest = 0;
        int lastInvalidIndex = strLength;
        int curInvalidIndex = 0;

        while(!matcher.empty())
        {
            curInvalidIndex = matcher.top(); matcher.pop();
            longest = max(longest, lastInvalidIndex - curInvalidIndex - 1);
            lastInvalidIndex = curInvalidIndex;
        }

        longest = max(longest, lastInvalidIndex);
 
        return longest;
    }

// DP Solution:
   int longestValidParentheses(string s) {
            if(s.length() <= 1) return 0;
            int curMax = 0;
            vector<int> longest(s.size(),0);
            for(int i=1; i < s.length(); i++){
                if(s[i] == ')'){
                    if(s[i-1] == '('){
                        longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                        curMax = max(longest[i],curMax);
                    }
                    else{ // if s[i-1] == ')', combine the previous length.
                        if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                            curMax = max(longest[i],curMax);
                        }
                    }
                }
                //else if s[i] == '(', skip it, because longest[i] must be 0
            }
            return curMax;
        }
