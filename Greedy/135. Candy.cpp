    int candy(vector<int>& ratings) 
    {
        int size = ratings.size();
        int candies = size;

        int i = 1;

        while(i < size)
        {
            if(ratings[i] == ratings[i - 1])
            {
                i++;
            }

            // Increasing Slope -->

            int peak = 0;
            while(i < size && ratings[i] > ratings[i - 1])
            {
                peak++;
                candies += peak;
                i++;
            }

            int valley = 0;
            // Decreasing Slope -->
            while(i < size && ratings[i] < ratings[i - 1])
            {
                valley++;
                candies += valley;
                i++;
            }

            candies -= min(peak, valley);
        }

        return candies;
    }
