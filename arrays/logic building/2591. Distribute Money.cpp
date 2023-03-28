// My initial Solution:

int distMoney(int money, int children) 
    {
        if(money < children)
        {
            return -1;
        }
        if(children*8 < money)
        {
            return children-1;      // last child gets the excess.
        }

        int moneyLeft = money%8;    // after alloting 8, we're left with this amount of money.
        int child8 = money/8;       // after alloting 8, these children could be alloted 8.

        if(moneyLeft == 4 && children-child8 == 1)
        {
            return --child8;
        }
        if(moneyLeft < children - child8)
        {
            child8 -= ((children-child8-moneyLeft)/7) + ((children-child8-moneyLeft)%7 != 0);
        }

        return child8;
    }

// A better approach involves giving each child 1 dollar beforehand to avoid de-alloting alloted candidates to fit them in. It's a better greedy choice.

int distMoney(int m, int c)
    {
        if(m < c) return -1;
        m-=c;   // allot 1 dollar to each child!

        if(7*c < m) return c-1;                 // if there is so much money!
        if(7*c == m) return c;                  // if equal money
  
        int seven = m/7;                        // we can allot these, 8 dollars.
        int rem   = m%7;                        // money Left -- give to any left child.
        if(m == (c-1)*7+3 and rem == 3) return c-2; // if we could give 8 dollars to c-1 children and we had 4 dollars left, we need balance it with another child.
        return seven;
        
    }
