class Solution {
public:
    // Rabin-Karp Algorithm for String Matching

    int BASE = 1e7;

    bool rabinKarp(string word, string pattern)
    {
        if(word == "" or pattern == "")
        {
            return -1;
        }

        int patSize = pattern.size();
        int strSize = word.size();

        int power = 1;
        for(int i = 0; i < patSize; i++)
        {
            power = (power * 31) % BASE; 
        }

        int patRollHash = 0;
        for(int i = 0; i < patSize; i++)
        {
            patRollHash = (patRollHash * 31 + (pattern[i] - 'a' + 1)) % BASE;
        }

        int strWindowRollHash = 0;

        for(int i = 0; i < word.size(); i++)
        {
            strWindowRollHash = (strWindowRollHash * 31 + (word[i] - 'a' + 1)) % BASE;
            if(i < patSize - 1) 
                continue;
            if(i >= patSize)
            {
                strWindowRollHash = (strWindowRollHash - (word[i - patSize] - 'a' + 1)*power) % BASE;
            }
            if(strWindowRollHash < 0)
                strWindowRollHash += BASE;

            if(strWindowRollHash == patRollHash)
            {
                if(word.substr(i - patSize + 1, patSize) == pattern)
                    return true;
            }
        }

        return false;

    }

    int repeatedStringMatch(string a, string b) 
    {
        if(a == b)
        {
            return 1;
        }

        int count = 1;
        string word = a;

        while(word.size() < b.size())
        {
            count++;
            word += a;
        }

        if(word == b)
        {
            return count;
        }

        if(rabinKarp(word, b))
        {
            return count;
        }

        if(rabinKarp(word+a, b))
        {
            return count+1;
        }
        return -1;

    }
};
