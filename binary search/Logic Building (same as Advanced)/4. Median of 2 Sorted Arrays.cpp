// Video Explanation Link (in English): https://www.youtube.com/watch?v=NTop3VTjmxk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=66&ab_channel=takeUforward

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Binary Search method.

        // first a cutting point in both arrays is needed, cut1 for nums1, cut2 for nums2. This cutting point will imply that if had to merge both sorted arrays
        // to form one sorted array then its first half would in elements beforer cut1 index in nums1 and before cut2 index in nums2 and the second half after the cuts.
        // basically trying to figure out what the middle elements would have been if we had merged the arrays without actually merging them. We are able to do this
        // since the ttwo arrays are sorted and so we have binary search.

        if(nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);         // ensuring that binary search happens on smaller size array
        }

        int size1 = nums1.size();
        int size2 = nums2.size();
        int left = 0;
        int right = size1;                                       // we have already ensured that size1 <= size2 [so index will not go out of bounds for nums2]

        while(left <= right)
        {
            int cut1 = (left + right) >> 1;                      // this acts as "mid" -- the ideal cut we need to find!
            int cut2 = ((size1+size2+1)>>1) - cut1;              // this is what cut2 will be.
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];        // left side element of cut position in array1
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];        // right side element of cut position in array2
            int r1 = cut1 == size1 ? INT_MAX : nums1[cut1];      // left side element of cut position in array1
            int r2 = cut2 == size2 ? INT_MAX : nums2[cut2];      // right side element of cut position in array2

            if(l1 <= r2 && l2 <= r1)                             // the rest properties are by default true as nums1 and nums2 are sorted.
            {
                // this cutting position produces left and right side of merged sorted arrays.
                if((size1 + size2)%2 == 0)
                {
                    // even case
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            if(l1 > r2)
            {
                right = cut1 - 1;
            }
            else
            {
                left = cut1 + 1;
            }
        }

        return 0.0;
    }
