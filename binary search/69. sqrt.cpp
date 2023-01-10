int mySqrt(int x) {
        // binary search and that is it.
        if(x==0)
        return 0;

        int start = 1;
        int end = x;
        int mid = start + (end-start)/2;
        int ans = 0;
        
        while(start <= end)
        {
            
            if(mid == x/mid)
            {
                return mid;
            }
            if(mid < x/mid)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end-start)/2;

        }   
        return ans;     
    }
