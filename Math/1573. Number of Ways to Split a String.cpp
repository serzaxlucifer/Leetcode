/*
      It's not hard to figure out that we're basically trying to figure out number of ways we can form s2.
      Firstly, the sum of total ones must be divisible by 3. Then each string s1, s2, s3 must have its sum as totalSumofOnes/3 (say eachSum).

      Say this is our string, where total ones are 9. So each string s1,s2,s3 must have 3 ones.

             0   1   0   0   1   0   0   1   0   0   0    1    0    1    1    0    0    0    1    1    0    1    0    0
prefixSum:   0   1   1   1   2   2   2   3   3   3   3    4    4    5    6    6    6    6    7    8    8    9    9    9
index:       0   1   2   3   4   5   6   7   8   9   10   11   12   13   14   15   16   17   18   19   20   21   22   23
             <--------  s1  ------------->                <----   s2  --->                   <----------- s3 ---------->
                                             <-------->                       <---------->
                                          can either be a                 can either be a part
                                          part of s1 or s2.               of s2 or s3.

                                          size of pool = n                size of pool = m

                                          ^               ^                ^                 ^
                                          |               |                |                 |
                             s2MayHaveLeftCut    s2MustHaveLeftCut     s2MustHaveRightCut   s2MayHaveRightCut

                             Thus, n = s2MustHaveLeftCut - s2MayHaveLeftCut AND m = s2MayHaveRightCut - s2MustHaveRightCut
             
      So, its evident that s1 will atleast contain indices 0 to 7. s2 will contain atleast indices 11-14 and s3 will contain atleast 18-23.
      There's a pool of zeros we get between s1 and s2 (indices 8-10) that can either be part of s1 or s2.
      Similarly, There's a pool of zeros we get between s2 and s3 (indices 15-17) that can either be part of s2 or s3.

      The number of ways we can select them (the zeros in between the must have part) in s2 is our answer! If they aren't in s2, then they're automatically a part of their counterpart.
      Say between indices 8 - 10. We have 3 zeros, we can choose them in s2 as: s1 |000 s2, s1 0|00 s2, s1 00|0 s2, s1 000| s2 (basically n + 1). and similarly m + 1 on the right side.
      Then left and right side combinations will be (n+1)*(m+1). And that's the answer.

      If string has all zeros. Then how can you choose s2? s1's must Have part will be index 0. and s3's will be len-1. (len-2) 0's number of ways to choose consecutive zeros in s2 is the answer.
      The formula to do that is fLen + fLen*(fLen-1)/2   ; where fLen = len - 2;      CHATGPT this if you can't understand the logic of this formula.
  */

class Solution {
    int MOD = 1e9+7;
public:
    int numWays(string s) 
    {
        // we're basically computing number of ways in which we can form s2 such that its sum is prefix[len - 1]/3

        vector<int> prefix(s.length(), 0);
        prefix[0] = s[0] - '0';
        int len = s.length();

        for(int i = 1; i < len; i++)
        {
            prefix[i] = prefix[i - 1] + (s[i] - '0');
        }

        if(prefix[len - 1] % 3 != 0)
        {
            return 0;
        }
        if(prefix[len - 1] == 0)
        {
            int fLen = len-2;
            return (fLen + ((fLen*(long long)(fLen-1))/2))%MOD;
        }

        int onesInS2 = prefix[len - 1] / 3;
        int s2MustHaveLeftCut = -1, s2MustHaveRightCut = -1;
        int s2MayHaveLeftCut = -1, s2MayHaveRightCut = -1;        // the zeros surrounding the must have part.
        // we need to compute: (s2MustHaveLeftCut - s2MayHaveLeftCut + 1)*(s2MayHaveRightCut - s2MustHaveRightCut + 1)

        for(int i = 0; i < len; i++)
        {
            if(prefix[i] == onesInS2 && s2MayHaveLeftCut == -1)
            {
                s2MayHaveLeftCut = i + 1;
            }
            if(prefix[i] == onesInS2+1 && s2MustHaveLeftCut == -1)
            {
                s2MustHaveLeftCut = i;
            }
            if(prefix[i] == onesInS2*2+1 && s2MayHaveRightCut == -1)
            {
                s2MayHaveRightCut = i - 1;
            }
            if(prefix[i] == onesInS2*2 && s2MustHaveRightCut == -1)
            {
                s2MustHaveRightCut = i;
            }

        }

        return ((long long)(s2MustHaveLeftCut - s2MayHaveLeftCut + 1)*(long long)(s2MayHaveRightCut - s2MustHaveRightCut + 1))%MOD;
    }
};


// Can we improvise?
// Yes! Once we have found s2MayHaveRightCut, it means we have also found all other details like s2MustHaveLeftCut, s2MayHaveLeftCut, s2MustHaveRightCut. So we don't need to scan the rest of the string/prefixSum. End the for loop
// there itself. It brings time on Leetcode from 26% to 95%.

class Solution {
    int MOD = 1e9+7;
public:
    int numWays(string s) 
    {
        // we're basically computing number of ways in which we can form s2 such that its sum is prefix[len - 1]/3

        vector<int> prefix(s.length(), 0);
        prefix[0] = s[0] - '0';
        int len = s.length();

        for(int i = 1; i < len; i++)
        {
            prefix[i] = prefix[i - 1] + (s[i] - '0');
        }

        if(prefix[len - 1] % 3 != 0)
        {
            return 0;
        }
        if(prefix[len - 1] == 0)
        {
            int fLen = len-2;
            return (fLen + ((fLen*(long long)(fLen-1))/2))%MOD;
        }

        int onesInS2 = prefix[len - 1] / 3;
        int s2MustHaveLeftCut = -1, s2MustHaveRightCut = -1;
        int s2MayHaveLeftCut = -1, s2MayHaveRightCut = -1;        // the zeros surrounding the must have part.
        // we need to compute: (s2MustHaveLeftCut - s2MayHaveLeftCut + 1)*(s2MayHaveRightCut - s2MustHaveRightCut + 1)

        for(int i = 0; i < len; i++)
        {
            if(prefix[i] == onesInS2 && s2MayHaveLeftCut == -1)
            {
                s2MayHaveLeftCut = i + 1;
            }
            if(prefix[i] == onesInS2+1 && s2MustHaveLeftCut == -1)
            {
                s2MustHaveLeftCut = i;
            }
            if(prefix[i] == onesInS2*2+1)
            {
                if(s2MayHaveRightCut == -1)      // Prune the search here! No need to scan the rest.
                s2MayHaveRightCut = i - 1;

                else
                break;
            }
            if(prefix[i] == onesInS2*2 && s2MustHaveRightCut == -1)
            {
                s2MustHaveRightCut = i;
            }

        }

        return ((long long)(s2MustHaveLeftCut - s2MayHaveLeftCut + 1)*(long long)(s2MayHaveRightCut - s2MustHaveRightCut + 1))%MOD;
    }
};

// Can we further space-optimize? YES! We don't need the prefixSuM vector. A simple variable will suffice bringing our space complexity to O(1).

class Solution {
    int MOD = 1e9+7;
public:
    int numWays(string s) 
    {
        // we're basically computing number of ways in which we can form s2 such that its sum is prefix[len - 1]/3

        int prefixSum = 0;
        int len = s.length();

        for(int i = 0; i < len; i++)
        {
            prefixSum = prefixSum + (s[i] - '0');
        }

        if(prefixSum % 3 != 0)
        {
            return 0;
        }
        if(prefixSum == 0)
        {
            int fLen = len-2;
            return (fLen + ((fLen*(long long)(fLen-1))/2))%MOD;
        }

        int onesInS2 = prefixSum / 3;
        int s2MustHaveLeftCut = -1, s2MustHaveRightCut = -1;
        int s2MayHaveLeftCut = -1, s2MayHaveRightCut = -1;        // the zeros surrounding the must have part.
        // we need to compute: (s2MustHaveLeftCut - s2MayHaveLeftCut + 1)*(s2MayHaveRightCut - s2MustHaveRightCut + 1)

        int curSum = 0;

        for(int i = 0; i < len; i++)
        {
            curSum += s[i] - '0';
            if(curSum == onesInS2 && s2MayHaveLeftCut == -1)
            {
                s2MayHaveLeftCut = i + 1;
            }
            if(curSum == onesInS2+1 && s2MustHaveLeftCut == -1)
            {
                s2MustHaveLeftCut = i;
            }
            if(curSum == onesInS2*2+1)
            {
                if(s2MayHaveRightCut == -1)
                s2MayHaveRightCut = i - 1;

                else
                break;
            }
            if(curSum == onesInS2*2 && s2MustHaveRightCut == -1)
            {
                s2MustHaveRightCut = i;
            }

        }

        return ((long long)(s2MustHaveLeftCut - s2MayHaveLeftCut + 1)*(long long)(s2MayHaveRightCut - s2MustHaveRightCut + 1))%MOD;
    }
};


