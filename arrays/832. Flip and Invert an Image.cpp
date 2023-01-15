vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int size = image.size();

        for(int i = 0; i < size; i++)
        {
            int s = 0;
            int e = size-1;

            while(s < e)
            {
                int temp =!(image[i][e]);
                image[i][e] =!image[i][s];
                image[i][s] = temp;
                s++, e--;
            }

            if(size%2 == 1)
            {
                image[i][size/2] = !(image[i][size/2]);
            }
        }

       
