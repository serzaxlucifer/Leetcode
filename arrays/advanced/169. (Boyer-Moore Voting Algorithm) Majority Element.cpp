// Brute Force:

int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int size = nums.size();
        int freq = size/2;

        for(int i : nums)
        {
            map[i]++;
        }

        for(auto& iter : map)
        {
            if(iter.second > freq)
            {
                return iter.first;
            }
        }

        return nums[0];


    }
//-----------------------------------------------------------------------------------------------------------------------
// A Simple Approach:
// sort it and the required element WILL ALWAYS BE AT nums.size()/2 index of the vector. So SIMPLE!! AHHHHHHHH!!!!!!!

int majorityElement(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

//-----------------------------------------------------------------------------------------------------------------------

// ---- The solutions below are a courtesy of LeetCode Admin ---- //
// https://leetcode.com/problems/majority-element/solutions/127412/majority-element/

// Another Approach: Bit Manipulation
/*
Intuition:
If an element majority_element occurs more than n/2 times, then there are at least n/2 elements of identical values with num at each bit. That is, we can reconstruct the exact value of num by combining the most frequent value (0 or 1) at each bit.

Algorithm:
Starting from the least significant bit, we enumerate each bit to determine which value is the majority at this bit, 0 or 1, and put this value to the corresponding bit of the result. Finally, we end up with the most least significant bit of all elements and return the result.
*/
int majorityElement(vector<int>& nums) {
        // Bit manipulation

        int element = 0;
        int size = nums.size();

        for(int i = 0; i < 32; i++)
        {
            int bit = 1 << i;
            int count = 0;
            for(auto i : nums)
            {
                if((i & bit) != 0)
                {
                    count++;
                }
            }
            if(count > size/2)
            {
                element |= bit;
            }
        }

        return element;
    }
//-----------------------------------------------------------------------------------------------------------------------
// Randomization: (rand() function to generate the index)
// Because a given index is likely to have the majority element, we can just select a random index, check whether its value is the majority element, return if it is, and repeat if it is not. The algorithm is verifiably correct because we ensure that the randomly chosen value is the majority element before ever returning.

// I did not write the code for this as this does not seem to be good algorithm to me as its time complexity could reach O(infinity). **It is highly unreliable.**

//-----------------------------------------------------------------------------------------------------------------------
// Divide and Conquer: (Interesting)
/*
Here, we apply a classical divide & conquer approach that recurses on the left and right halves of an array until an answer can be trivially achieved for a length-1 array. Note that because actually passing copies of subarrays costs time and space, we instead pass lo and hi indices that describe the relevant slice of the overall array. In this case, the majority element for a length-1 slice is trivially its only element, so the recursion stops there. If the current slice is longer than length-1, we must combine the answers for the slice's left and right halves. If they agree on the majority element, then the majority element for the overall slice is obviously the same1. If they disagree, only one of them can be "right", so we need to count the occurrences of the left and right majority elements to determine which subslice's answer is globally correct. The overall answer for the array is thus the majority element between indices 0 and n.
*/

int countInRange(vector<int>& nums, int low, int high, int target)
    {
        int count = 0;
        for(int i = low; i <= high; i++)
        {
            if(nums[i] == target)
            count++;
        }
        return count;
    }

    int majorityElement(vector<int>& nums) {
        // Divide and Conquer

        return majorityElementRecursion(nums, 0, nums.size()-1);
    }

    int majorityElementRecursion(vector<int>& nums, int low, int high)
    {
        if(low == high)
        {
            return nums[low];
        }

        int mid = low + (high - low)/2;
        int left = majorityElementRecursion(nums, 0, mid);
        int right = majorityElementRecursion(nums, mid +1, high);

        if(left == right)
        {
            return left;
        }

        int leftCount = countInRange(nums, low, mid, left);
        int rightCount = countInRange(nums, mid+1, high, right);

        return (leftCount > rightCount) ? left : right;
    }

//-----------------------------------------------------------------------------------------------------------------------
// O(n) Time Complexity and O(1) Space Complexity Solution: Boyer-Moore Voting Algorithm
int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        int candidate = 0;
        int size = nums.size();
        int count = 0;

        for(int i = 0; i < size; i++)
        {
            if(count == 0)
            candidate = nums[i];

            count += (candidate == nums[i]) ? 1 : -1;
        }

        return candidate;
        
    }


