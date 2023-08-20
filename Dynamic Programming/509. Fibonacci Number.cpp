// The most basic solution could be the one involving recursion.

int fib(int n)
{
  if(n == 1 || n == 0)
  {
    return n;
  }

  return fib(n-1) + fib(n-2);
}

// But here you will observe that many values are being re-computed again and again. Imagine n = 5.
// The first call of fib invokes two other calls fib1(4) and fib1(3) to find them.
// The function call fib(4) invokes two other calls fib2(3) and fib2(2). So we see that fib(3) is being computed twice.
// As the recursion tree grows, the recomputations will increase drastically suggesting that this is a very unoptimized algorithm.

// What do we do to avoid recomputations? DYNAMIC PROGRAMMING!
// Let's see a bottom-up iterative approach.

    int fib(int n) 
    {
        int array[31];
        array[0] = 0;
        array[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            array[i] = array[i-1] + array[i-2];  // no recomputation. We build from base requirements.
        }

        return array[n];
    }

// To further tweak this, can we reduce space usage to O(1)? Surely! Just think on a piece of paper.

    int fib(int n) 
    {
        int zero = 0;       // current solution looking at n = 0
        int one = 1;        // next solution looking at n = 0

        for(int i = 0; i < n; i++)
        {
            swap(one, zero);    // shift next solution to current solution and update next solution.
            one += zero;
        }

        return zero;
    }


