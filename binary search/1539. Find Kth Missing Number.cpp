// My first implementation: O(n) Solution: [It is trash, both space wise and time wise!]

int findKthPositive(vector<int>& arr, int k) {
        // O(n) Solution

        vector<int> missing;
        int size = arr.size();
        int count = 1;

        for(int i = 0; i < size; )
        {
            if(arr[i] != count)
            {
                missing.emplace_back(count);
                count++;
                continue;
            }
            i++;
            count++;
        }

        missing.emplace_back(arr[size-1]);              // otherwise if missing array is empty, it causes issues!
        size = missing.size();
        if(k < size)
        {
            return missing[k-1];
        }
        else
        {
            return missing[size-1] + (k-size+1);
        }
    }

// I can optimize this O(N) further, space-wise. This is the best O(n) Solution.

int findKthPositive(vector<int>& arr, int k) {
        // O(n) Solution

        int size = arr.size();
        int count = 1;
        int countOfMissing = 0;

        for(int i = 0; i < size; )
        {
            if(arr[i] != count)
            {
                countOfMissing++;
                if(countOfMissing == k)
                {
                    return count;
                }
                count++;
                continue;
            }
            i++;
            count++;
        }

        return arr[size-1] + (k-countOfMissing);
    }


// You wouldn't believe BUT this can be optimized further keeping O(n) time! It just struck to me to use Indexes as basis of computation. A proper array's 
// element values should be: arr[i] = i + 1;  [ no number skipped till now ].     [BEATS 90% in RunTime]

int findKthPositive(vector<int>& arr, int k) {
        // O(n) Solution

        int size = arr.size();
        int countOfMissing = 0;

        for(int i = 0; i < size; i++)
        {
            if(arr[i] != i + 1 + countOfMissing)
            {
                countOfMissing += arr[i] - (i+1+countOfMissing);
            }
            if(countOfMissing >= k)
            {

                return arr[i] - (countOfMissing-k+1);
            }
        }

        return arr[size-1] + (k-countOfMissing);
    }

// Optimizing Time Complexity: INPUT IS SORTED so, the task now is to find how we can use Binary Search to our aid! Let's think how!!
// Now in order to perform Binary Search, I need to think in the following sequence: The first element to be tested will be in the middle. Now on what criteria,
// do I decide if I want to stop here or go left or right. One of things I thought of from my previous solution to use as a condition was to use the index-value
// difference to decide where I want to go. [arr[i] = i + 1]. Let's see how that would look like in code.

int findKthPositive(vector<int>& arr, int k) {
        // O(log(n)) Solution -- BINARY SEARCH

        int size = arr.size();
        int start = 0;
        int end = size;
        int mid = (start + end) / 2;

        while(start < end)
        {
            if(arr[mid] - mid - 1 < k)
            start = mid + 1;
            else
            end = mid;

            mid = (start + end) / 2;
        }

        return start + k;
    }



