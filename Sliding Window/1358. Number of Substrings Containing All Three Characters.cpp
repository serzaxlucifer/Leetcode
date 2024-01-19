int numberOfSubstrings(string s) 
    {
        int count[3] = {0, 0, 0};
        int total = 0;
        int j = 0;

        for(int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;

            while(count[0] && count[1] && count[2])
            {
                --count[s[j++] - 'a'];
            }

            total += j;
        }

        return total;
    }
