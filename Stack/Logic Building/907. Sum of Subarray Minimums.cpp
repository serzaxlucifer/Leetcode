// Monotone Stack:

class Solution 
{
    int MOD = 1e9+7;

    public:

    int sumSubarrayMins(vector<int>& arr) 
    {
        int sum = 0;
        stack<int> st;

        for(int right = 0; right < arr.size() + 1; right++)
        {
            int curVal = (right < arr.size()) ? arr[right] : 0;     // 0 will pop the entire stack to emptiness!

            while(!st.empty() && curVal < arr[st.top()])
            {
                int index = st.top(); st.pop();
                int cutLeft = 0;
                if(st.empty())
                {
                    cutLeft = -1;
                }
                else
                {
                    cutLeft = st.top();
                }

                int leftCount = index - cutLeft;
                int rtCount = right - index;

                sum = ( sum + ((leftCount*rtCount*(long)arr[index])%MOD)) % MOD;
            }

            st.push(right);
        }

        return sum;
        
    }
};

// Dynamic Programming Concepts:

/* [https://leetcode.com/problems/sum-of-subarray-minimums/solutions/170769/java-o-n-monotone-stack-with-dp/]

stack: Increasing stack, store the index
dp[i + 1]: Sum of minimum of subarrays which end with A[i]
dp[i + 1] = dp[prev + 1] + (i - prev) * A[i], where prev is the last number which is less than A[i], since we maintain a monotonous increasing stack, prev = stack.peek()

eg. [3, 1, 2, 4, 3], when i = 4, all subarrays end with A[4]:
[3]
[4, 3]
[2, 4, 3]
[1, 2, 4, 3]
[3, 1, 2, 4, 3]
In this case, stack.peek() = 2, A[2] = 2.
For the first 2 subarrays [3] and [4, 3], sum of minimum = (i - stack.peek()) * A[i] = 6.
For the last 3 subarrays [2, 4, 3], [1, 2, 4, 3] and [3, 1, 2, 4, 3], since they all contain a 2 which is less than 3, sum of minimum = dp[stack.peek() + 1] = 4.
Then, dp[i + 1] = 4 + 6 = 10

*/

int sumSubarrayMins(vector<int>& A) 
{
        stack<int> st;
        vector<int>dp(A.size()+1); 
        st.push(-1);
        int result = 0, M = (int)1e9 + 7;
        for (int i = 0; i < A.size(); i++) {
            while (st.top() != -1 && A[i] <= A[st.top()]) {
                st.pop();
            }
            dp[i + 1] = (dp[st.top() + 1] + (i - st.top()) * A[i]) % M;
            st.push(i);
            result += dp[i + 1];
            result %= M;
        }
        return result;
    }
