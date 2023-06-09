// Using an Ordered Map() --> Insertion of order O(log(N)). Thus, overall time complexity becomes O(2*N*log(k)). Our overall goal however
// is to reduce this time complexity to O(N) which we will discuss below. 

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> answer;
        int size = nums.size();

        map<int, int> map;
        int i = 0;

        for(; i < k; i++)
        {
            map[nums[i]]++;
        }

        answer.emplace_back(map.rbegin()->first);
        i = 0;

        while(i + k < size)
        {
            map[nums[i+k]]++;           // O(logk) time
            map[nums[i]]--;

            if(map[nums[i]] == 0)
            {
                map.erase(nums[i]);     // O(logk) time
            }

            answer.emplace_back(map.rbegin()->first);
            i++;
        }
        
        return answer;
    }

/* This solution yields a runtime of 10% in 750ms which is terrible. Extremely terrible. Let's quickly get onto Optimizations as the above runtime is just nauseating. This is
   no better than O(Nk) time. */

// The Question also tags the use of Priority Queues (same concept as above ordered map implementation) AND Deques. Let's explore these options. Remember we want to iterate just 
// once or a constant number of times through the array.

/* Utilizing DEQUE: Basically, for each element nums[i] in the array that we are about to insert, we first check whether the leftmost index in the sliding window is out of bound. If so, 
   we remove it in constant time. Then we continuously remove the rightmost indices if their corresponding elements are less than nums[i] (the element we are about to insert). 
   The idea is that the elements that are less than the element we'll insert won't have any contributions to the maximum element of the sliding window. So it is safe to remove them.
   After removal and insertion (the element nums[i]), we can say that the leftmost element in the window is maximum. Think about it why. Notice that the 
   maximum element could be the one we just insert.

   Courtesy of https://leetcode.com/problems/sliding-window-maximum/solutions/458121/java-all-solutions-b-f-pq-deque-dp-with-explanation-and-complexity-analysis/ */

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        int size = nums.size();

        deque<int> window;

        for(int i = 0; i < size; i++)
        {
            if(window.size() > 0 && window.front() <= i - k)
            {
                window.pop_front();
            }

            while(window.size() > 0 && nums[window.back()] < nums[i])
            {
                window.pop_back();
            }

            window.push_back(i);

            if(i >= k-1)
            {
                answer.emplace_back(nums[window.front()]);
            }
        }

        return answer;
        
    }

/* Runtime: 91% ~ 296ms --> almost half of before! Efficiency of our algorithm has almost doubled and that is amazing. On an average, this algorithm consumes
   O(N) time, very close to it. */

// Can you use the Dynamic Programming Paradigm? You can definitely see some sorts of re-computation in brute force implementation of O(Nk) time. Can 
// you figure out some way to employ DP? So I understand why DP works, but what's the intuition that tells you "Rather than using a sliding window, I can use segments of
// two (left and right) static windows (blocks) to get from O(nk) to O(n)?"

vector<int> maxSlidingWindow(vector<int>& nums, int k)  // DP Solution
    {
        vector<int> answer;
        int size = nums.size();

        int *left = new int [size];
        int *right = new int [size];
        left[0] = nums[0];
        right[size - 1] = nums[size - 1];

        for(int i = 1; i < size; i++)
        {
            if(i % k == 0)
            {
                left[i] = nums[i];
            }
            else
            {
                left[i] = max(left[i-1], nums[i]);
            }

            int endIndex = size - 1 - i;
            if(endIndex % k == (k - 1))
            {
                right[endIndex] = nums[endIndex];
            }
            else
            {
                right[endIndex] = max(right[endIndex + 1], nums[endIndex]);
            }
        }

        for(int i = 0, j = i + k - 1; j < size; i++, j++)
        {
            answer.emplace_back(max(right[i], left[j]));
        }

        delete [] left;
        delete [] right;

        return answer;
        
    }

// Runtime: 95% and 99.6% when cout and cin are tied to NULL by appending this line as first line of the function:
std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


