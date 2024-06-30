// PLEASE READ '2872. Maximum Number of K-Divisible Components.cpp' first!

class Solution {
    bool bfs(int val, vector<vector<int>> &al, vector<int> q, vector<int> n, vector<int> cnt) 
    {
        while(!q.empty()) 
        {
            vector<int> q1;
            for (auto i : q) 
            {
                if (n[i] > val)
                    return false;
                for (auto j : al[i]) 
                {
                    n[j] += n[i] < val ? n[i] : 0;
                    if (--cnt[j] == 1)
                        q1.push_back(j);
                }
            }
            swap(q, q1);
        }
        return true;
    }
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n = nums.size(), sum = accumulate(begin(nums), end(nums), 0);
        if (sum % n == 0 && all_of(begin(nums), end(nums), [&](int v){ return v == sum / n; }))
            return n - 1;

        vector<vector<int>> al(n);

        for (auto &e : edges) 
        {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        vector<int> q, cnt(n);
        
        for (int i = 0; i < n; ++i) 
        {
            cnt[i] = al[i].size();
            if (al[i].size() == 1)
                q.push_back(i);
        }

        for (int i = n - 1; i > 1; --i)
        {
            if (sum % i == 0 && bfs(sum / i, al, q, nums, cnt))
            {
                return i - 1;
            }
        }

        return 0;
    }
};
