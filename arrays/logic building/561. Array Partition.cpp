// now i know this question is super easy but i found something amazing so i'll still put it under Logic Building.

// My initial solution (Greedy choice basically):

int arrayPairSum(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        sort(nums.begin(), nums.end());     // nlogn
        int answer = 0;

        int low = nums.size() - 2;
        while(low >= 0)
        {
            answer += nums[low];
            low--;
            low--;
        }

        return answer;
    }

// and yes! this is how it has to be done! So what can I change? Sorting algorithm! Yep, It can be optimized further.
// to my observation, using inbuilt sort performs worse than using counting sort in this question. The reason I speculate is that counting pool 
// size is 20001 ( 10000 (negative numbers) + 1 (for zero) + 10000 (positive numbers) ). So the best choice of sorting here is Counting Sort.

// Incredible speed of 99.95% when tied with ios_base::sync_with_stdio(false);

int arrayPairSum(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int min = INT_MAX;      // optimize space further.
        int max = INT_MIN;

        for (int num : nums)
        {
            if (num > max)
            {
                max = num;
            }
            if (num < min)
            {
                min = num;
            }
        }

        int *freqArr = new int[max - min + 1]{};     // only what is required!
        for (int num : nums)
        {
            freqArr[num - min] ++;
        }

        int answer = 0;

        int skip = 0;
        for (int i = 0; i < (max - min + 1); i++)
        {
            while (freqArr[i] > 0)
            {
                if (!skip)
                {
                    answer += (i + min);
                    skip = 1;
                }
                else 
                {
                    skip = 0;
                }
                freqArr[i]--;
            }    
        }

        delete[] freqArr;               // delete the space used.

        return answer;
    }
