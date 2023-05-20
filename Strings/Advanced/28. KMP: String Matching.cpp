// Utilize KMP Algorithm. For multiple set pattern matching, use Rabin Karp algo.
// Advanced Searching Algorithms : Boyer Moore, Aho-Corasick (forms basis of UNIX command 'fgrep')

// KMP Solution:

class Solution {
public:
    int strStr(string haystack, string needle) {
        // Knuth-Morris-Pratt Algorithm

        // Compute LPS
        int a = haystack.length();
        int b = needle.size();

        int LPS[b];
        LPS[0] = 0;
        int j = 0;

        for(int i = 1; i < b; i++)
        {
            if(needle[i] == needle[j])
            {
                LPS[i] = ++j;
            }
            else
            {
                if(j == 0)
                {
                    LPS[i] = j;
                }
                else
                {
                    j = LPS[j-1];
                    i--;
                }
            }
        }

        // Now perform searching according to KMP algorithm.
        int i = 0;
        j = 0;

        while((a-i) >= (b-j))       // further prune loop space, remove any extra infeasible iterations
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }

            if(j == b)
            {
                return i-b;
            }

            else if(haystack[i] != needle[j])
            {
                if(j == 0)
                {
                    i++;
                }
                else
                {
                    j = LPS[j-1];
                }
            }
        }

        return -1;

    }
};
