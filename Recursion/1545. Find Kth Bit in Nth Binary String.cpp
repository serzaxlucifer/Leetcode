// My Initial Solution:

class Solution {
public:
    char findKthBit(int n, int k) 
    {
        string s1 = "0";
        string finall;

        for(int i = 1; i < n; i++)
        {
            modifier(s1, s1.length());
        }

        return s1[k-1];
    }

    void modifier(string& s, int length)
    {
        s += "1";
        s += s;
        s.pop_back();

        int start = length+1;
        int end = s.length()-1;

        while(start <= end)
        {
            swap(s[start], s[end]);
            if(s[start] == '0')
            {
                s[start] = '1';
            }
            else
            {
                s[start] = '0';
            }
            if(start != end)
            {
            if(s[end] == '0')
            {
                s[end] = '1';
            }
            else
            {
                s[end] = '0';
            }
            }
            start++, end--;
        }

    }
};

// Now binary Search:

char findKthBit(int n, int k) 
    {
        // Track how does bit is being transformed since origin.

        if(n == 1)
        {
            return '0';
        }

        int length = (1 << n) - 1;        // length at stage n = 2^n - 1

        if(k == (length >> 1) + 1)
        {
            // mid bit
            return '1';
        }

        else if(k < (length >> 1) + 1)
        {
            return findKthBit(n - 1, k);
        }

        else
        {
            return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
        }

    }

// Here, is an iterative soln:

char findKthBit(int n, int k) 
    {
        // Iterative

        int length = (1 << n) - 1;
        int flip = 0;

        while(k > 1)
        {
            if(k == length/2 + 1)
            {
                return '0' + (flip ^ 1);;
            }

            if(k > length/2 + 1)
            {
                k = length + 1 - k;
                flip ^= 1;
            }

            length /= 2;
        }

        return '0' + flip;

    }
