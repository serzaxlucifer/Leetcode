    string smallestSubsequence(string s) 
    {
        string result = "";
        int size = s.length();
        int last[26] = {};
        bool seen[26] = {};

        for(int i = 0; i < size; i++)
        {
            last[s[i] - 'a'] = i;
        }

        for(int i = 0; i < size; i++)
        {
            if(seen[s[i] - 'a'])
            {
                continue;
            }
            seen[s[i] - 'a'] = true;

            while(!result.empty() && result.back() > s[i] && last[result.back() - 'a'] > i)
            {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(s[i]);
        }
        return result;
    }
