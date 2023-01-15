// my initial solution 28% RT (Brute Force Implementation)

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int validSize = m+1;
        int n1 = 0;
        int n2 = 0;
        while(n2 < n)
        {
            
            while(nums1[n1] < nums2[n2])
            {
                if(n1 == validSize-1)
                {
                    break;
                }
                n1++;
            }
            int temp = nums1[n1];
            nums1[n1] = nums2[n2];
            for(int i = n1+1; i < validSize; i++)
            {
                int temp2 = nums1[i];
                nums1[i] = temp;
                temp = temp2;
            }
            validSize++;
            n2++;
        }
    }

// Better sol: 3 Pointer approach i.e. Using given information that maximum size to be used is already allocated in nums1 vector, how can I remove the internal FOR Loop as well? That is the challenge which can be easily rectified by the 3 pointer approach i.e. you start filling in the arrays from their end itself!

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int p1 = m-1;       // end of nums1
        int p2 = n-1;       // end of nums2
        int p3 = m+n-1;     // where we write

        while(p1 >= 0 && p2 >= 0)
        {
            if(nums1[p1] < nums2[p2])
            {
                // place at last
                nums1[p3] = nums2[p2];
                p2--, p3--;
            }
            else
            {
                nums1[p3] = nums1[p1];
                p3--, p1--;
            }
        }
        while(p2 >= 0)
        {
            nums1[p3] = nums2[p2];
            p2--, p3--;
        }
    }

