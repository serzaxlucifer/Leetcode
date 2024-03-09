    int calculate(string s) 
    {
        int len = s.length();
        if(len == 0) return 0;

        int curNum = 0, lastNum = 0, result = 0;
        char operation = '+';

        for(int i = 0; i < len; i++)
        {
            if(isdigit(s[i]))
            {
                curNum = (curNum*10) + (s[i] - '0');
            }

            if(!isdigit(s[i]) && !iswspace(s[i]) || i == len - 1)
            {
                if(operation == '-' || operation == '+')
                {
                    result += lastNum;
                    lastNum = (operation == '+') ? curNum : -curNum;
                }
                else if(operation == '*')
                {
                    lastNum = lastNum * curNum;
                }
                else if(operation == '/')
                {
                    cout << curNum << "  ";
                    lastNum = lastNum / curNum;
                }

                operation = s[i];
                curNum = 0;
            }
        }

        result += lastNum;
        return result;
    }
