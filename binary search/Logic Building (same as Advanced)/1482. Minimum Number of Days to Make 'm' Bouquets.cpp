int minDays(vector<int>& bloomDay, int m, int k) {                    // [beats 99.6% solutions]
        if(m > bloomDay.size()/k)                   // never possible!
        {
            return -1;
        }

        // now proceed to Calculate.
        // lets find our search space first: [min, max]

        int max = INT_MIN;
        int min = INT_MAX;

        for(int& i : bloomDay)
        {
            max = (max < i) ? i : max;
            min = (min > i) ? i : min;
        }

        int mid;
        int minDays = max;

        while(min <= max)
        {
            mid = (min + max) >> 1;
            if(itIsPossible(bloomDay, mid, m, k))
            {
                // then look for an even smaller value
                max = mid - 1;
                minDays = (minDays > mid) ? mid : minDays;
            }
            else
            {
                // try for a bigger value.
                min = mid + 1;
            }
        }

        return minDays;
    }

    bool itIsPossible(vector<int>& arr, int days, int bouquets, int flowers)
    {
        int bouquetsMade = 0;
        int count = 0;
        for(int& i : arr)
        {
            if(i <= days)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(count == flowers)
            {
                count = 0;
                bouquetsMade++;
            }
        }
        return bouquetsMade >= bouquets;
    }
