    int findMinDifference(vector<string>&timePoints) {      // Bucket Sort
        vector<bool> bucket(1441, false);

        for(string s : timePoints)
        {
            int sum1=((int)(s[0]-'0')*10+(int)(s[1]-'0'))*60;
            int sum2=((int)(s[3]-'0')*10+(int)(s[4]-'0'));
          
            int mintvalue=sum1+sum2;
          
            if(bucket[mintvalue])
            {
                return 0;
            }
            else
            {
                bucket[mintvalue] = true;
            }
        }

        int difference=1441;
        int prev = 0;
        int first = INT_MAX, last = INT_MIN;


        for (int j = 0; j < 1440; j++)
        {
            if(bucket[j])
            {
                if(first != INT_MAX)
                {
                    difference = min(difference, j - prev);
                }
                first = min(first, j);
                last = max(last, j);
                prev = j;
            }
        }
        
        difference = min(difference, 1440 - last + first);
        return difference;
    }
