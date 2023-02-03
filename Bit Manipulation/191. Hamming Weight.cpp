// Always try to use bitwise operators.

int hammingWeight(uint32_t n) {
        int count = 0;

        while(n)
        {
            count++;
            n &= (n-1);
        }

        return count;
    }

// if n = 001100100 then n-1 should be: 001100011. Just a number smaller in terms of Binary.
