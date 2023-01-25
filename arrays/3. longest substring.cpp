int lengthOfLongestSubstring(string s)
    {
        int array[255];
        memset(array, -1, sizeof(array));  
        int size = s.length();
        int maxLen = 0;
        int begin = 0;

        for(int i = 0; i < size; i++)  
        {
            if(array[s[i]] != -1)
            {
                begin = max(begin, array[s[i]]+1);
            }
            array[s[i]] = i;
            maxLen = max(maxLen, i - begin + 1);
        }

        return maxLen;
    }

// 2nd:

int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> record;
        int maxLen = 0, begin = 0, n=s.length();
        for(int i = 0; i < n; ++i)
        {
            if(record.count(s[i]) !=0)
            { 
                begin = max(begin, record[s[i]]+1);
            }
            record[s[i]] = i;
            maxLen = max(maxLen, i - begin +1);
        }
        return maxLen;
  
}
