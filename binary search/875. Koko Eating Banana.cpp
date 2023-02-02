int minEatingSpeed(vector<int>& piles, int h) {
        int maxBound = INT_MIN;
        for(int& i : piles)
        {
            maxBound = maxBound < i ? i : maxBound;
        }

        int k = maxBound;

        // Search Space: [1, ....., maxBound]. Apply Binary Search here!
        int start = 1;
        int end = maxBound;
        int mid = (start + end) >> 1;
        while(start <= end)
        {
            if(sheCanEatAll(piles, h, mid))
            {
                end = mid - 1;              // try for a smaller value.
                k = mid;
            }
            else
            {
                start = mid + 1;            // smaller values wont work!
            }
            mid = (start + end) >> 1;
        } 

        return k;
    }

    bool sheCanEatAll(vector<int>& piles, int h, long speed)
    {
        long hours = 0;
        for(int i : piles)
        {
            if(i <= speed)
            {
                hours++;
            }
            else
            {
                hours += ((i+speed-1)/speed);
                // ceil: (a+b-1) / b
            }
        }

        return (hours <= h);
    }

// Further Optimization: (Instead of finding MAX VALUE, we can try using maximum value of the constraint of pile length. That trade off may reduce runtime in some cases and increase it in some.)

int minEatingSpeed(vector<int>& piles, int h) {
        int maxBound = 1000000000;
        int k = maxBound;

        // Search Space: [1, ....., maxBound]. Apply Binary Search here!
        int start = 1;
        int end = maxBound;
        int mid = (start + end) >> 1;
        while(start <= end)
        {
            if(sheCanEatAll(piles, h, mid))
            {
                end = mid - 1;              // try for a smaller value.
                k = mid;
            }
            else
            {
                start = mid + 1;            // smaller values wont work!
            }
            mid = (start + end) >> 1;
        } 

        return k;
    }

    bool sheCanEatAll(vector<int>& piles, int h, long speed)
    {
        long hours = 0;
        for(int i : piles)
        {
            if(i <= speed)
            {
                hours++;
            }
            else
            {
                hours += ((i+speed-1)/speed);
                // ceil: (a+b-1) / b
            }
        }

        return (hours <= h);
    }
