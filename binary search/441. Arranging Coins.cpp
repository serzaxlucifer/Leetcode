// Brute Force:
int arrangeCoins(int n) 
    {
        int steps = 0;
        int stepSize = 1;

        while(stepSize <= n)
        {
            steps++;
            n -= stepSize;
            stepSize++;
        }

        return steps;
    }

// To improvise, we can use Binary Search. If you're strong in mathematics, you'll realize that the concept of Arithmetic Progression sum can be implemented here.

int arrangeCoins(int n) 
    {
        // Say our search space is [0, n] and for p steps, you require total of p(p+1)/2 coins [sum of arithmetic progression].

        int start = 0;
        int end = n;
        int mid = (start + end)/2;

        while(start <= end)
        {
            long long p = ((long long)mid*(mid+1))/2;

            if(p == n)
            {
                return mid;
            }
            else if(p > n)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = (start + end)/2;
        }

        return start-1;
    }
