// Brute Force:

/*
Let's suppose you are at any given index, (REFER TO THE FIGURE IN QUESTION), you want to calculate how much water this index will contribute? How do you do that?
Say you're index = 5. You first identify the maximum height pillar on the left and on the right i.e. 3 and 7. Ofc, the maximum water it can contribute is the minimum of those two. i.e. 3 which has 
a height of 2, so it can contribute 2 water units!

Now, suppose you're at index = 6, left max pillar = 3 and right = 7, here as well height of 3rd index i.e. 2 is minimum, so it can contribute 2 - 1(its own height) = 1 unit.

Now say you are on a pillar that is highest in its domain and doesn't contribute any water -- how do you handle this? Observe that on all such cases, the pillar itself is maximum height
on either one of the sides or both the sides (that is also the only way it makes sense logically). The algorithm below will now make sense.

It is also clear that index 0 and last index can not contribute any water.

*/
int trap(vector<int>& height) {
        // lets do this!
        int size = height.size();
        int water = 0;

        for(int i = 1; i < size-1; i++)
        {
            int left = 0, right = 0;

            for(int j = i; j >= 0; j--)
            {
                if(height[j] > left)
                {
                    left = height[j];
                }
            }

            for(int j = i; j < size; j++)
            {
                if(height[j] > right)
                {
                    right = height[j];
                }
            }

            water += min(left, right) - height[i];
        }

        return water;
    }

// This will result in time limit exceeded. Of course. Now simplify it! The first thing to check: SO MUCH RECOMPUTATION!! We're re-calculating same results for different indexes
// Use dynamic programming guidelines! Use extra storage to rescue. Simply as you iterate, store all the left maxes and right maxes in 2 iterations and use them. Compute this data only once.

int trap(vector<int>& height) {
        // lets do this!
        int size = height.size();
        int water = 0;

        int dp_left[size];
        int dp_right[size];
        dp_left[0] = height[0];
        dp_right[size-1] = height[size-1];

        for(int i = 1; i < size; i++)
        {
            dp_left[i] = max(height[i], dp_left[i-1]);
            dp_right[size-i-1] = max(height[size-i-1], dp_right[size-i]); 
        }

        for(int i = 1; i < size-1; i++)
        {
            water += min(dp_left[i], dp_right[i]) - height[i];
        }

        return water;
    }

// TC: O(n) but SC = O(n) Can you reduce space to a constant? Let's think! Try using 2 pointers, at beginning and end. Can we resolve the answer at an index without having the array data?
/*
From the figure in dynamic programming approach, notice that as long as right_max[i]>left_max[i]\text{right\_max}[i]>\text{left\_max}[i]right_max[i]>left_max[i] (from element 0 to 6), the water 
trapped depends upon the left_max, and similar is the case when left_max[i]>right_max[i]\text{left\_max}[i]>\text{right\_max}[i]left_max[i]>right_max[i] (from element 8 to 11).
So, we can say that if there is a larger bar at one end (say right), we are assured that the water trapped would be dependant on height of bar in current direction (from left to right). As 
soon as we find the bar at other end (right) is smaller, we start iterating in opposite direction (from right to left).
We must maintain left_max\text{left\_max}left_max and right_max\text{right\_max}right_max during the iteration, but now we can do it in one iteration using 2 pointers, switching between the
two.  [Courtesy of LeetCode Editorial]
*/

int trap(vector<int>& height) {
        
        int size = height.size();
        int water = 0;

        int left = 0, right = size-1;
        int lmax = 0, rmax = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                height[left] >= lmax ? (lmax = height[left]) : water += (lmax - height[left]);
                ++left;
            }
            else
            {
                height[right] >= rmax ? (rmax = height[right]) : water += (rmax - height[right]);
                --right;
            }
        }

        return water;
    }
// there can't be a faster solution.

