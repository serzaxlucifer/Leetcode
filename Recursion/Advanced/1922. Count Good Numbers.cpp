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



