// Dynamic Programming Solution:

int minFlipsMonoIncr(string s) {
        int ones  = 0;
        int flips = 0;
        for(auto i : s)
        {
            if(i == '0')
            {
                flips++;
            }
            else
            {
                ones++;
            }
            flips = min(flips, ones);
        }

        return flips;
    }

// Brute Force Approach:

int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> ones(n, 0);
        vector<int> zeros(n, 0);
        int flips = INT_MAX;
        int zeross = 0;
        int oness = 0;

        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == '1')
            {
                oness++;
            }
            ones[i+1] = oness;
        }

        for(int i = n-1; i > 0; i--)
        {
            if(s[i] == '0')
            {
                zeross++;
            }
            zeros[i-1] = zeross;
        }

        for(int i = 0; i < n; i++)
        {
            flips = min(flips, zeros[i]+ones[i]);
        }

        return flips;
    }
