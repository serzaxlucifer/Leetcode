    int maxChunksToSorted(vector<int>& arr) 
    {
        int soln = 0;
        int maxi = -1;

        for(int i = 0; i < arr.size(); i++)
        {
            maxi = max(maxi, arr[i]);
            if(maxi == i)
            {
                soln++;
            }
        }

        return soln;  
    }
