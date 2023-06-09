// Brute Force O(nlogn) Sorting Based:   runtime: 40% ~ 40ms

int findUnsortedSubarray(vector<int>& nums) 
    {
        int size = nums.size();
        int *arr = new int [size];
        for(int i = 0; i < size; i++)
        {
            arr[i] = nums[i];
        }

        sort(arr, arr + size);

        int i = 0; 
        int start, end;

        while(i < size && arr[i] == nums[i])
        {
            i++;
        }
        start = i;
        i = size-1;

        while(i >= 0 && arr[i] == nums[i])
        {
            i--;
        }
        end = i;

        delete [] arr;

        return start >= end ? 0 : end - start + 1;
    }


// Now, let's optimize. Can we do without sorting at all?
// Brute Force in O(n2) without sorting.

int findUnsortedSubarray(vector<int>& nums) 
{       // EXCEEDS TIME LIMIT!!
  
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size() - 1; i++) 
        {
            for (int j = i + 1; j < nums.size(); j++) 
            {
                if (nums[j] < nums[i]) 
                {
                    r = max(r, j);
                    l = min(l, i);
                }
            }
        }
  
        return r - l < 0 ? 0 : r - l + 1;
    }

// How to optimize time? To O(N) basically. In other words, No NESTED LOOPING.

/*
    GUIDELINES TO DO THAT:
    
    1. Find the smallest number (S) which isn't in order
    2. Find the largest number (L) which isn't in order
    3. Find the correct position for the smallest number (S), lets call it (l)
    4. Find the correct position for the largest number (L), lets call it (r)
    5. If (r-l < 0) Answer = 0 else Answer = (r-l+1)
*/

// Code with O(1) Space and O(N) time.

// Go read editorial solution first which uses 4 for loops to do this. All that work is packed into 1 for loop here.
int findUnsortedSubarray(vector<int>& nums) 
    {
        int min = INT_MAX;
        int max = INT_MIN;

        int start = -1;
        int end = -1;

        int size = nums.size();
        int left = 0, right = size - 1;
        
        while(right >= 0)
        {
            if(max > nums[left])
            {
                end = left;
            }
            else
            {
                max = nums[left];
            }

            if(min < nums[right])
            {
                start = right;
            }
            else
            {
                min = nums[right];
            }

            ++left;
            --right;
        }

        return start == -1 ? 0 : end - start + 1;
    }
// sigh.... i just wish I had some brain.



