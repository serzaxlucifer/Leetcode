    int minAddToMakeValid(string s) 
    {
        int openers = 0;
        int minOps = 0;

        for(char a : s)
        {
            if(a == '(')
            {
                openers++;
            }
            else
            {
                if(openers == 0)
                {
                    minOps++;
                }
                else
                {
                    openers--;
                }
            }
        }

        minOps += openers;

        return minOps;
    }
