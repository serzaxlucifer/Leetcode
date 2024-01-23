    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        if(hand.size() % groupSize)
        {
            return false;
        }

        map<int, int> mymap;

        for(int i : hand)
        {
            mymap[i]++;
        }        

        for(auto i : mymap)
        {
            if(i.second > 0)
            {
                for(int j = 1; j < groupSize; j++)
                {
                    if((mymap[i.first+j] -= mymap[i.first]) < 0)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }



