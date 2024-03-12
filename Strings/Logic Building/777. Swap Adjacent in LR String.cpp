// EXTREME BRUTE FORCE:

    bool canTransform(string start, string end) 
    {
        // Basically you can shift L's leftwards and R's rightwards as long as the replacements are 'X'.

        int i = 0;          // start pointer
        int j = 0;          // end pointer
        int limit = start.length();

        while(j < limit)        // parse the end string manipulating the start string as and when necessary.
        {
            if(start[i] == end[j])
            {
                i++, j++;
            }

            else if(end[j] == 'L' && start[i] == 'X')
            {
                int replacement = i;
                while(i < limit && start[i] == 'X')
                {
                    i++;
                }
                if(i < limit && start[i] == 'L')
                {
                    swap(start[i], start[replacement]);
                    i = replacement;
                    i++, j++;
                }
                else
                {
                    return false;
                }
            }
            else if(end[j] == 'X' && start[i] == 'R')
            {
                int replacement = i;
                while(i < limit && start[i] == 'R')
                {
                    i++;
                }
                if(i < limit && start[i] == 'X')
                {
                    swap(start[i], start[replacement]);
                    i = replacement;
                    i++, j++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }

        }

        return true;
    }

// OH BOY. terrible runtime.
// Let's clean it up.

    bool canTransform(string start, string end) 
    {
        // Basically you can shift L's leftwards and R's rightwards as long as the replacements are 'X'.

        int i = 0;          // start pointer
        int j = 0;          // end pointer
        int limit = start.length();

        while(i < limit || j < limit)
        {
            while(i < limit && start[i] == 'X')
            {
                i++;
            }
            while(j < limit && end[j] == 'X')
            {
                j++;
            }

            if(i >= limit || j >= limit)
            {
                break;
            }

            if(start[i] != end[j])
            {
                return false;
            }
            
            if(start[i] == 'L' && j > i)
            {
                return false;
            }

            if(start[i] == 'R' && i > j)
            {
                return false;
            }

            i++, j++;
        }

        return i == j;
    }
