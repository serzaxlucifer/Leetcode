// Initial Idea: Yes ofcourse, a priority queue.

int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;

        for(int i : nums)
        {
            pq.push(-i);

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        return -pq.top();
    }

// But this has poor performance. 33% runtime @ 150ms ~ O(N*log(k))

// Let's talk of optimization. There's apparently an algorithm known as Hoare's Selection Algorithms that specializes in these things and does them more efficiently.
// PLEASE read the editorial at https://leetcode.com/problems/kth-largest-element-in-an-array/editorial/

class Solution {  
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int pivot = nums[rand() % nums.size()];     // generate a random pivot.

        vector<int> left, mid, right;

        for(int i : nums)
        {
            if (i < pivot) 
            {
                right.push_back(i);
            } 
            else if (i > pivot) 
            {
                left.push_back(i);
            } 
            else 
            {
                mid.push_back(i);
            }
        }

        if(k <= left.size())
        {
            return findKthLargest(left, k);
        }

        if(left.size() + mid.size() < k)
        {
            return findKthLargest(right, k - left.size() - mid.size());
        }

        return pivot;
    }

};

// Another Approach: Counting Sort    // runtime: 99.85% (59ms)

int findKthLargest(vector<int>& nums, int k) 
    {
        std::ios_base::sync_with_stdio(false); cin.tie(NULL);

        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        int size = nums.size();
        
        for(int i = 0; i < size; i++)
        {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }

        int* freq = new int[maxVal-minVal+1];
        memset(freq, 0, sizeof(int)*(maxVal-minVal+1));

        for(int i : nums)
        {
            freq[i - minVal]++;
        }

        for(int i = maxVal-minVal; i >= 0; i--)
        {
            k -= freq[i];
            if(k <= 0)
            {
                delete [] freq;
                return i + minVal;
            }
        }

        delete [] freq;

        return -1;
    }


