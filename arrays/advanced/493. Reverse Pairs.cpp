/*
From LeetCode:

Partition recurrence relation

For partition recurrence relation, setting i = 0, j = n - 1, m = (n-1)/2, we have:

T(0, n - 1) = T(0, m) + T(m + 1, n - 1) + C

where the subproblem C now reads "find the number of important reverse pairs with the first element of the pair coming from the left subarray nums[0, m] while the second
element of the pair coming from the right subarray nums[m + 1, n - 1]".

Again for this subproblem, the first of the two aforementioned conditions is met automatically. As for the second condition, we have as usual this plain linear scan
algorithm, applied for each element in the left (or right) subarray. This, to no surprise, leads to the O(n^2) naive solution.

Fortunately the observation holds true here that the order of elements in the left or right subarray does not matter, which prompts sorting of elements in both subarrays.
With both subarrays sorted, the number of important reverse pairs can be found in linear time by employing the so-called two-pointer technique: one pointing to elements
in the left subarray while the other to those in the right subarray and both pointers will go only in one direction due to the ordering of the elements.

The last question is which algorithm is best here to sort the subarrays. Since we need to partition the array into halves anyway, it is most natural to adapt it into a
Merge-sort. Another point in favor of Merge-sort is that the searching process above can be embedded seamlessly into its merging stage.

So here is the Merge-sort-based solution, where the function "reversePairsSub" will return the total number of important reverse pairs within subarray nums[l, r]. The
two-pointer searching process is represented by the nested while loop involving variable p, while the rest is the standard merging algorithm.

*/

// Code For Merge-Sort Based Algorithm:   [Beats 93% of the solutions]

int reversePairs(vector<int>& nums) {
        return enhancedMergeSort(nums, 0, nums.size()-1);
    }

    int enhancedMergeSort(vector<int>& nums, int left, int right)
    {
        if(left >= right)
        {
            return 0;                                                                     // nothing to process here.
        }

        int mid = left + ((right-left)>>1);                                               // bitwise operators are quicker than arithmetic ones.

        int reverseCount = enhancedMergeSort(nums, left, mid) + enhancedMergeSort(nums, mid+1, right);                     // do such pairs exist independently in left and right subarrays? How many?

        // At this point I also know that the left and right subarrays are sorted. So all I need to is calculate how many pairs exist with one in one subarray and the second element in another. 

        int i = mid + 1;
        int j = mid + 1;
        int k = 0;
        int e = right;
        int s = left;
        int merged[right - left + 1];

        while(s <= mid)         // till left subarray runs out.
        {
            // first count the reverse pairs.
            while(i <= e && nums[s] > 2L*nums[i])
            {
                i++;
            }
            reverseCount += i - (mid+1);

            // then merge in a sorted fashion.

            while(j <= e && nums[s] >= nums[j])
            {
                merged[k++] = nums[j++];
            }
            merged[k++] = nums[s++];
        }

        while (j <= e) merged[k++] = nums[j++];

        for(int m = left; m <= right; m++)
        {
            nums[m] = merged[m-left];
        }

        return reverseCount;

    }

// Now let's talk about further optimizations! Well, if you're looking to further break down runtime, you can use class variables, arrays (instead of vectors) for processing. That way you don't have to pass arrays that many times. Use object oriented paradigms.
