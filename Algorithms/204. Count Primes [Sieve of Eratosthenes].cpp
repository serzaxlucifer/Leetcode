int countPrimes(int n) {
        int count = 0;

        vector<bool> prime(n+1, true);

        prime[0] = prime[1] = false;

        for(int i = 2; i < n; i++)
        {
            if(prime[i] == true)
            {
                count++;

                for(int j = i; j < n; j = j + i)
                {
                    prime[j] = false;
                }
            }
        }

        return count;
    }      // runtime: 86%

// This algorithm is called Sieve of Eratosthenes with time complexity: O(n*log(log(n))) [The time complexity expression will form a harmonic progression series and using taylor series, this result can be derived.]
