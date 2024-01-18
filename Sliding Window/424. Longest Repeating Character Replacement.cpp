int characterReplacement(string s, int k) 
    {
        int count[26] = {0};
        int maxLength = 0;
        int maxCount = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++)
        {
            maxCount = max(maxCount, ++count[s[i] - 'A']);
            if(i - start - maxCount + 1 > k)
            {
                --count[s[start++] - 'A'];
            }
            maxLength = max(maxLength, i-start+1);
        }

        return maxLength;
    }
