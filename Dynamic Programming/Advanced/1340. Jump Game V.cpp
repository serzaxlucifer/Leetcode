// Dynamic Programming:  (approach 1)
// The general approach is to construct a DAG {Directed Acyclic Graph} from possible jumps downward, then find the longest path using DFS. This gives time complexity O(nd). To achieve O(n) time
// complexity, we instead consider possible jumps upward, and note the nearest higher positions are sufficient. These can be found efficiently using monotone stacks (approach 2).

class Solution {
public:
    int dp[1001] = {0};

    int maxJumps(vector<int>& arr, int d) 
    {
        int soln = 1;
        for(int i = 0; i < arr.size(); i++)
        {
            soln = max(soln, DFS(arr, i, d));
        }

        return soln;
    }

    int DFS(vector<int>& arr, int start, int d)
    {
        if(dp[start])
        {
            return dp[start];
        }
        int soln = 1;

        for(int i = start + 1; i <= min((int)arr.size() - 1, start + d) && arr[i] < arr[start]; i++)
        {
            soln = max(soln, 1+DFS(arr, i, d));
        }

        for(int i = start - 1; i >= max(0, start - d) && arr[i] < arr[start]; i--)
        {
            soln = max(soln, 1+DFS(arr, i, d));
        }   

        return dp[start] = soln;
    }
};

// Approach 2: Monotone Stack

    int maxJumps(vector<int>& arr, int d) 
    {
        int soln = 1;
        stack<int> st;

        vector<int> DP(arr.size(), 1);

        for(int i = 0; i < arr.size(); i++)
        {
            while(!st.empty() && arr[i] > arr[st.top()])
            {
                int idx = st.top(); st.pop();
                int m = 0;

                for(int j = idx+1; j < i && j - idx <= d; j++)
                {
                    if(arr[j] == arr[idx])
                    {
                        break;
                    }
                    m = max(m, DP[j]);
                }

                DP[idx] = max(DP[idx], m+1);

                if(i - idx <= d)
                {
                    DP[i] = max(DP[i], 1 + DP[idx]);
                }
            }
            st.push(i);
        }

        while(!st.empty())
            {
                int idx = st.top(); st.pop();
                int m = 0;

                for(int j = idx+1; j < arr.size() && j - idx <= d; j++)
                {
                    if(arr[j] == arr[idx])
                    {
                        break;
                    }
                    m = max(m, DP[j]);
                }

                DP[idx] = max(DP[idx], m+1);
            }

            for(int i : DP)
            {
                soln = max(soln, i);
            }


        return soln;
    }
