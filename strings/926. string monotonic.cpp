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
