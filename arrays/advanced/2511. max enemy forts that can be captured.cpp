// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/ 

// 0ms RunTime Solution: (Single Pointer and Single Traversal)
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
    int captureForts(vector<int>& forts) 
    {
        int maxCapture = 0;
        int basesCaptured = 0;

        int capturing = 0;
        int size = forts.size(); 

        for(int i = 0; i < size; i++)
        {
            if(forts[i] == 1)
            {
                if(capturing == 2)
                {
                    maxCapture = (maxCapture >= basesCaptured) ? maxCapture : basesCaptured;
                }
                capturing = 1;
                basesCaptured = 0;
            }
            else if(forts[i] == 0)
            {
                if(capturing != 0)
                {
                    basesCaptured++;
                }
            }
            else
            {
                if(capturing == 1)
                maxCapture = (maxCapture >= basesCaptured) ? maxCapture : basesCaptured;
                capturing = 2;
                basesCaptured = 0;
            }
        }

        return maxCapture;
    }

// another solution:

int captureForts(vector<int>& forts) 
    {
        int maxCapture = 0;
        int deployPoint = 0;
        int relocationPointIndex = -1;

        bool capturing = false;
        int size = forts.size(); 

        for(int i = 0; i < size; i++)
        {
            if(forts[i] == 1)
            {
                relocationPointIndex = i;
                if(capturing)
                {
                    maxCapture = (maxCapture >= i-deployPoint-1) ? maxCapture : i-deployPoint-1;
                    deployPoint = 0;
                }
                capturing = false;
            }
            else if(forts[i] == -1)
            {
                if(relocationPointIndex != -1)
                {
                    maxCapture = (maxCapture >= i-relocationPointIndex-1) ? maxCapture : i-relocationPointIndex-1;
                }
                deployPoint = i;
                relocationPointIndex = -1;
                capturing = true;
                
            }
        }

        return maxCapture;
    }

// smallest code:

int captureForts(vector<int>& forts) 
    {
        int maxCapture = 0;
        int size = forts.size(); 
        int pointOfInterest = 0;

        for(int i = 0; i < size; i++)
        {
            if(forts[i] != 0)
            {
                if(forts[pointOfInterest] == -forts[i])
                {
                    maxCapture = (maxCapture >= (i-pointOfInterest-1)) ? maxCapture : (i-pointOfInterest-1); 
                }
                pointOfInterest = i;
            }
        }

        return maxCapture;
    }
