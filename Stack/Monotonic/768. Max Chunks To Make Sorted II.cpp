// Greedy: [courtesy of @shawngao: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/solutions/113462/java-solution-left-max-and-right-min/]

    int maxChunksToSorted(vector<int>& arr) 
    {
        vector<int> suffixMin(arr.size());
        suffixMin[arr.size() - 1] = arr[arr.size() - 1];

        for(int i = arr.size() - 2; i >= 0; i--)
        {
            suffixMin[i] = min(suffixMin[i + 1], arr[i]);
        }

        int maxi = arr[0];
        int soln = 0;

        for(int i = 0; i < arr.size() - 1; i++)
        {
            maxi = max(maxi, arr[i]);
            if(maxi <= suffixMin[i + 1])
            {
                soln++;
            }
        } 

        return soln + 1;
    }


// Monotonic Stack: [courtesy of @combat_shawn: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/solutions/595713/monotonic-stack-solution-with-detailed-explanation/]
/*
    Understanding how monotonic stack works (build an increasing or decreasing stack based on the input) and what it can do is relatively easy. 
    Unfortunately the hardest part is solution based on monotonic stack is sometimes not intuitive.

    Here's the thought based on this question.

    First question, what is the largest number of chunks for an array given the length as n? it's simple, just n, namingly every single element makes up the single-element chunk. 
    For a given array, the largest number of chunks happens when it is increasing and every element is already at the right place.
    [0, 1, 3, 4] => [0, 1], [3], [4]

    So as long as we are seeing an array that has increasing order, we just keep counting the number of elements in the array. 
    (If you are familiar with monotonic stack, have you already smelled that it could be something useful to solve this question?)

    Let's keeping counting, untill we see the next element 2. So now the input is [0, 1, 3, 4, 2]
    Well what does a suddenly jumped out smaller number mean ?? It means, 2 is not at the right place in the sorted array 
    (we can see 2 actually should sit at the 3rd place in the array right?), and SOMETHING ELSE before 2 is also at the wrong place, which we didn't realize until we see 2. 
    So we need to look back.

    (While, another hint, we are expecting an increasing order array and we have to look backwards when the order is broken. Does this smell like monotonic stack again?)

    So what exactly are we looking for when we are looking back?
    We want to find the correct place that 2 should sit at, which means: We are looking for the largest number that is smaller than 2 in an ascending array. 
    Why we care about where 2 should be at? because anything between the current position and the should-be position for 2 is not at the correct position that it should be 
    (otherwise how could the poor 2's potion being occupied?). If we can find the elements (including 2) that are not at the right position, they need to be put in a chunk, and sorting them inside the chunk is the only way to put them in right place.

    So in this example: [0, 1, 3, 4, 2], we found 1 is the largest number smaller than 2 given our monotonic stack [0, 1, 3, 4]. 
    So everything between 3 and 2 (inclusive) is messed up and they [3, 4, 2] has to be put in a chunk, so we can sort them back to [2, 3, 4] and put them back to the right place.

    Normally, we rebuild the monotonic stack from [0,1, 3, 4] to [0, 1, 2] by poping out the elements larger than 2 and push 2 back to the queue. 
    However this doesn't work for this question.

    Let's think about what exactly the meaning we want it to be for each element in the increasing stack.

    We want it to mean: The largest value in each chunk when the chunk cannot be partitioned to smaller ones. So the number of elements in the stack is exactly the number we are looking for.

    So now the stack became [0, 1, 4] instead of [0, 1, 2] and each 0 => [0], 1 => [1], 4 => [3, 4, 2].

    In a nutshell, MODEL THE MONOTONIC STACK AS STACK CONTAINING MAXIMUM OF EACH POSSIBLE CHUNK. THEN RETURN LENGTH OF STACK! 2 Operations: Create new chunk, merge 2 chunks.
*/

    int maxChunksToSorted(vector<int>& arr) 
    {
        stack<int> st;

        for(int i = 0; i < arr.size(); i++)
        {
            int largest = arr[i];

            while(!st.empty() && st.top() > arr[i])
            {
                largest = max(largest, st.top());
                st.pop();
            }

            st.push(largest);
        } 

        return st.size();
    }
