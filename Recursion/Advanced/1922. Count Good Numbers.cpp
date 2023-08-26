static const int MOD = 1e9 + 7;         // modulo

    int countGoodNumbers(long long n) 
    {
        // Can we proceed with a O(N) solution first?
        // Also recall property of Modular Arithmetic: (a*b)mod m = ((a mod m)*(b mod m))mod m

        long long result = 1;

        int primeDigits = 4;
        int evenDigits = 5;

        for(int i = 0; i < n; i++)
        {
            if(i%2 == 0)
            {
                result = (result * (evenDigits % MOD)) % MOD;
            }
            else
            {
                result = (result * (primeDigits % MOD)) % MOD;
            }
        }

        return result % MOD;
    }

    // This is HOWEVER A BAD WAY TO DO THIS. IT CAN BE HIGHLY OPTIMIZED TO O(log N)! Also know that n = 806166225460393 is test case!! O(n) is a very bad solution thus. 

// There's a concept called Exponentiation. Read: https://cp-algorithms.com/algebra/binary-exp.html

/*
    At even places, we have 5 choices and 4 choices at odd places, say there are 'a' even places and 'b' odd places, we're basically computing (5^a * 4^b) mod m. And what's the best way to 
    compute a^n? Binary Exponentiation! Read: https://cp-algorithms.com/algebra/binary-exp.html
*/


static const int MOD = 1e9 + 7;         // modulo

    long long power(long long x, long long y)
    {
        x %= MOD;
        long long result = 1;

        if(x == 0)
        {
            return 0;
        }

        while(y > 0)
        {
            if (y & 1) 
            {
                result = (result * x) % MOD;
            }

            y = y>>1; 

            x = (x * x) % MOD;

        }

        return result;
    }

    int countGoodNumbers(long long n) 
    {
        long long result = 0;

        long long int count_PRIMEPLACES = n/2;               // 4 digits possible!
        long long int count_EVENPLACES = n - n/2;            // 5 digits possible!

        result = ((power(4, count_PRIMEPLACES) % MOD) * (power(5, count_EVENPLACES) % MOD)) % MOD;

        return (int)result;
    }
