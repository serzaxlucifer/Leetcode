    int calculate(string s) 
    {
        int n = s.size(), result = 0, sign = 1;
        stack<int> stk;
        
        for (int i = 0; i < n; i++) 
        {
            if (isdigit(s[i])) 
            {
                int num = s[i] - '0';
                while (i + 1 < n && isdigit(s[i + 1])) 
                {
                    num = num * 10 + (s[++i] - '0');
                }
                result += sign * num;
            } 

            else if (s[i] == '+') 
            {
                sign = 1;
            } 
            else if (s[i] == '-') 
            {
                sign = -1;
            } 

            else if (s[i] == '(') 
            {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } 

            else if (s[i] == ')') 
            {
                result *= stk.top();
                stk.pop();
                result += stk.top();
                stk.pop();
            }
        }
        return result;
    }
