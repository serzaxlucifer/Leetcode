// Solution 1:
bool rotateString(string s, string goal) {
        if(s == goal)
        {
            return true;
        }

        int size = s.length();

        for(int i = 1; i < size; i++)
        {
            s = s[size-1] + s.substr(0, size-1);      // too much work~
            if(s == goal)
            {
                return true;
            }
        }

        return false;

    }


// Another great solution USING string::npos  [(A+A).find(B) != string::npos]
bool rotateString(string s, string goal) {
        return (s.length() == goal.length()) && (s+s).find(goal) != string::npos;

    }

 
