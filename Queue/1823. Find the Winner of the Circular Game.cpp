// Brute Force:

int findTheWinner(int n, int k) 
    {
        queue<int> circle;
        

        for(int i = 0; i < n; i++)
        {
            circle.push(i+1);
        }

        for(int i = 0; i < n-1; i++)
        {
            for(int i = 0; i < k-1; i++)
            {
                int val = circle.front();
                circle.pop();
                circle.push(val);
            }

            circle.pop();
        }

        return circle.front();
    }

// Let's start optimizing to Constant memory AND Linear time.

int findTheWinner(int n, int k) 
    {
        int i=1, ans=0;
        while(i <= n)
        {
            ans=(ans+k)%i;
            i++;
        }
        return ans + 1;
    }

// Recursive Version:

int findTheWinner(int n, int k) 
  {
        if(n == 1) 
          return n;
        return (findTheWinner(n - 1, k) + k - 1) % n + 1;
    }
