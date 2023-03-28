string strWithout3a3b(int a, int b, char A = 'a', char B = 'b') {
        string solution = "";
        if(a < b)
        {
            return strWithout3a3b(b, a, 'b', 'a');
        }

        while(a > 0)
        {
            solution += A;
            a--;
            if(a > b)
            {
                // add more.
                solution += A;
                a--;
            }
            if(b > 0)
            {
                solution += B;
                b--;
            }
        }

        return solution;
    }

// Intuition:

/*
Say a > b,
The worst possible string in this case would be: aabaabaabaa | aabaa1, 4, aabaabaa 2, 6
i.e. a = 8, b = 3, or b can be more upto abababababababab or it can stretch to a = 3, b = 8.
In a nutshell, for the constraint to be satisfied, for any value of a, you can add a maximum of (2a+2) b's.

In case a = b,
simply do this: ababab....
But if a > b, at max: a = (2b+2)
that means, append two a's at beginning, and do this: aa + baabaabaa....
If a < 2b+2, then it could be aabaabaab...ababab

As simple as that. So while A>B, add 2 a's and when a = b, keep pushing abababab.

*/
