// First Solution (absolute brute force)

int distanceTraveled(int mainTank, int additionalTank) 
    {
        // Iterative Approach
        int miles = 0;
        if(mainTank < 5)
        {
            return mainTank*10;
        }
        else
        {
            miles += 50;
            mainTank -= 5;
        }

        for(int i = additionalTank; i >= 1; i--)
        {
            mainTank += 1;
            if(mainTank < 5)
            {
                break;
            }
            miles += 50;
            mainTank -= 5;
        }

        return miles + (mainTank)*10;

    }

// 91% runtime

// Another Way:

int distanceTraveled(int mainTank, int additionalTank) 
    {
        // Iterative Approach
        int dist = 0;

        for(int i=1; i<=mainTank; i++)
        {
            if(additionalTank != 0 && i%5 == 0)
            {
                additionalTank -= 1;
                mainTank += 1;
            }
            dist += 10;
        }
        return dist;

    }

// Recursive Approach:

int distanceTraveled(int mainTank, int additionalTank) 
    {
        // Recursive Approach
        if(mainTank < 5 || additionalTank == 0)
        {
            return mainTank*10;
        }

        mainTank -= 5;
        int distance = distanceTraveled(mainTank + 1, additionalTank - 1);

        return distance + 50;

    }
