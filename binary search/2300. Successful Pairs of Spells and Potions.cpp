// 1st Approach: The Obvious One. Sort Potions array and use Binary Search to find first such potions which fits the spell.

// Runtime: 50%

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(), potions.end());
        int size = spells.size();
        int potSize = potions.size();

        // One-time sort solution.

        for(int i = 0; i < size; i++)
        {
            int spellStrength = spells[i];
            int start = 0;
            int end = potSize-1;
            int mid = start + (end-start)/2;

            while(start <= end)
            {
                long long product = potions[mid]*(long long)spellStrength;

                if(product >= success)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }

                mid = start + (end-start)/2;
            }

            spells[i] = potSize - mid;
        }

        return spells;

    }

// Another approach you might have though of could be:

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<pair<int, int>> pairs;
        int size = spells.size();
        int potSize = potions.size();

        for(int i = 0; i < size; i++)
        {
            pairs.push_back({spells[i], i});        // this 'pairs' is not the same as the one given in problem statement.
        }

        sort(potions.begin(), potions.end());
        sort(pairs.begin(), pairs.end());

        // Two-time sort solution.

        int minPotion = potSize - 1;

        for(auto& [spell, index] : pairs)
        {
            while(minPotion >= 0 && (long long) spell * potions[minPotion] >= success)
            {
                minPotion--;
            }

            spells[index] = potSize - (minPotion + 1);
        }

        return spells;

    }

// This seems to perform even poorly than Approach 1, yielding a runtime of 5%.

//---------------------------------------------------------------------------------------------------------------------------

// Now trust me, you can optimize Approach 1. I'm just not willing to think that much :(
// huh, nevermind instead of regretting choosing this line of work, let's talk of fukcing optimization (*insert cry eye emoji here*)

// I will now discuss 3 other approaches, starting with the one that runs the quickest. GALLOP THEM, UNDERSTAND THEM TO STRENGTHEN YOUR BASICS.

// SOLUTION : MULTI-LOOP APPROACH (Suffix/Prefix Array Concept)   RUNTIME: 99%

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)   
    {
        int size = spells.size();
        int potSize = potions.size();

        int maxSpell = 0;
        for(int i = 0; i < size; i++)
        {
            maxSpell = max(spells[i], maxSpell);    
        }

        vector<int> counts(maxSpell + 1, 0);                          // counts[i] will tell how many potions can be combined with spells[i] (ith spell).

        for(int i = 0; i < potSize; i++)
        {
            long long minSpell = ceil(success/(double)potions[i]);    // for this potion, what should be minimum spell strength to achieve success?

            if(minSpell < maxSpell + 1)                               // if no spells is bigger enough, then zero contribution.
            {
                counts[minSpell]++;
            }
        }

        for(int i = 1; i < maxSpell + 1; i++)                         // all further spells can use the potions used by previous spells.
        {
            counts[i] += counts[i-1];
        }

        for(int i = 0; i < size; i++)
        {
            spells[i] = counts[spells[i]];
        }

        return spells;

    }

// We're trading space for very effective reduction in runtime.

// Another solution involves using bucket sort instead of usual sort.

int lb(int v[], int len, long long t)
{
        if(t > v[len-1])
            return len;
        int l = 0;
        int r = len-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if (v[mid] < t) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int p[100001] = {0};
        for(int i : potions)
            ++p[i];
        int pot[100001];
        int plen = 0;
        for(int i = 0; i < 100001;)     // bucket sort
            if (p[i]-- > 0)
                pot[plen++] = i;
            else
                i++;

        int len = spells.size();
        vector<int> ans(len);
        for(int i = 0; i < len; i++)
            ans[i] = plen - lb(pot, plen, (success + spells[i] - 1)/spells[i]);

        return ans;
    }
