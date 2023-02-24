// First brute force implementation [Extremely bad solution]: [5% runtime -- 1100ms]

int beautySum(string s) {
        int sum = 0;
        int size = s.length();
        for(int i = 0; i < size-1; i++)
        {
            for(int j = i+2; j <= size; j++)
            {
                sum += findBeauty(s.substr(i, j-i));
            }
        }

        return sum;
    }

    int findBeauty(string s)
    {
        int frequency[26] = {0};
        for(char a : s)
        {
            frequency[a-'a']++;
        }
        int max = INT_MIN, min = INT_MAX;

        for(int i : frequency)
        {
            if(i){
            max = (max >= i) ? max : i;
            min = (min <= i) ? min : i;}
        }

        return max-min;

    }

// Optimizations are definitely required and a lot!
// The first thing that I can see here is recomputation of same data many times. findBeauty() prepares a frequency array of first substring. and 
// recomputes the whole array even though just one additional element of the string is added.
// Say you have aabcb. First, it goes for aa, then for aab (it recomputes for aa and b additionally), then for aaba (it recomputes for aab then c additionally.)
// First and foremost, we MUST remove this recomputation of data before we can move onto further optimizations.

////////////////////////////////////
//////// MY SECOND SOLUTION ////////
////////////////////////////////////

// If we try using a same frequency array for literally every single computation, it doesn't work. There doesn't seem to be a way round it. But when we are computing for
// for substrings that originate from a single character (same), i.e. from same point like for aabcb -- we work with 'a'... the starting
// then for all substrings that originate from this a (the first a) we can use a same array and grow it as we expand the substring possible. like aa, aab, aabc i.e. 
// reducing recomputation of data. 

// However, this presents with one problem of min and max setting. Say you have a -- max = 1, min = 1. the next substring to come out is aa. so we simply add +1 to a
// in common frequency list and recompute min and max. max = 2, min = 1. BUT min should be 2 as there are no other characters in string yet. This problem arrises
// when we work on this model but has a quick fix as shown in the code below.

int beautySum(string s) {                       // Runtime: 99.88% (18ms)
        int sum = 0;
        int size = s.length();

        for(int i = 0; i < size-1; i++)
        {
            int frequency[26] = {0};
            int min = 0, max = 1;                   // put technical values. non reachable min here is 0 and max rechab;e max is 1 (to work in sync with else condition)

            for(int j = i; j < size; j++)
            {
                int &c = frequency[s[j] - 'a'];
                
                if(c)
                {
                    if(c++ == min)
                    {
                        for(int i = 0; i < 26; i++)
                        {
                            if(frequency[i] == min)
                            {
                                min--;
                                break;
                            }
                        }
                        min++;
                    }
                    if(c > max)
                    {
                        max = c;
                    }
                }
                else
                {
                    min = ++c;
                }

                sum += (max - min);
                
            }
        }

        return sum;
    }

