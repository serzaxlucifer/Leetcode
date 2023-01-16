// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/ 

// 0ms RunTime Solution:
int captureForts(vector<int>& forts) 
    {
        int maxCapture = 0;                     // if not possible to capture any base.
        int basesBefore = 0;                    // 
        int basesAfter = 0;                     // 
        int relocationPointIndex = -1;          // 
        int capturing = 0;                      // 
        int newCapture = 0;
        
        int lastPoint = -1;
        int lastAdded = 1;
        
        for(int i = 0; i < forts.size(); i++)
        {
            if(forts[i] == 1)
            {
                // needs relocation
                if(capturing == 1)
                basesBefore = i - lastPoint - 1;
                relocationPointIndex = i;
                lastAdded = 0;
                capturing = 0;
                
            }
            else if(forts[i] == -1)
            {
                // open spot encountered!
                capturing = 1;
                lastPoint = i;
                if(relocationPointIndex != -1)
                {
                    basesAfter = i-relocationPointIndex-1;
                    newCapture = max(basesAfter, basesBefore);
                    if(newCapture > maxCapture)
                    maxCapture = newCapture;
                }
                relocationPointIndex = -1;
                lastAdded = 1;
            }
        }
        if(lastAdded == 0)
        {
            if(basesBefore > maxCapture)
            maxCapture = basesBefore;
        }
        
        return maxCapture;
    }

// another solution:
