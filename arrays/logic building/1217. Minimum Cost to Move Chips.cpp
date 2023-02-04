int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;

        for(int i : position)
        {
            if(i & 1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }

        return min(even,odd);
    }
