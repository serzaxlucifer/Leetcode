// First Implementation:            [33% poor runtime]

bool isAnagram(string s, string t) {

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t);

    }

// Optimizing it further we have,   [95% runtime beat]

bool isAnagram(string s, string t) {
        if(s.length() != t.length())                // without this, the solution below fails for unequal strings.
        return false;
        
        int arr[26] = {0};                          // 97 - 122

        for(char a : s)
        {
            arr[a-97]++;
        }

        for(char a : t)
        {
            if((--arr[a-97]) < 0)
            {
                return false;
            }
        }

        return true;
    }

