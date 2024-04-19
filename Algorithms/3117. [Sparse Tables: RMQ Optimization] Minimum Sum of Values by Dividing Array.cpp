// Simple Dynamic Programming Solution:

    int solve(int i, int j, int val, vector<int>& nums, vector<int>& andValues, vector<vector<unordered_map<int, int>>>& dp) {
        if (i >= nums.size()) {
            if (j >= andValues.size()) return 0;
            else return 1000001;
        }
        if (j >= andValues.size()) return 1000001;

        if (dp[i][j].count(val)) return dp[i][j][val];

        if (val == -1) val = nums[i];
        else val = val & nums[i];

        int ans = INT_MAX;
        if (val == andValues[j]) {
            ans = nums[i] + min(ans, solve(i + 1, j + 1, -1, nums, andValues, dp));
            ans = min(ans, solve(i + 1, j, val, nums, andValues, dp));
        } else {
            ans = min(ans, solve(i + 1, j, val, nums, andValues, dp));
        }

        return dp[i][j][val] = ans;
    }

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        int m = andValues.size();
        if (m > n) return -1;
        
        // Initialize dp with default unordered_map
        vector<vector<unordered_map<int, int>>> dp(n + 1, vector<unordered_map<int, int>>(m + 1));

        int ans = solve(0, 0, -1, nums, andValues, dp);
        return ans > 1000000 ? -1 : ans;
    }

// VERY POOR RUNTIME!!
// Let's Optimize! (PRE-REQUISITES: RMQ (Sparse Tables), Binary Search/Segment Trees)

class Solution {
public:
    const int inf = 214748364;
    int AND[10002][20], logs[10002], dp[10002][11], n, m ;
    
    void compute_logs()      // avoid wasting time in recomputations!
    {
        logs[1] = 0;
        for(int i=2;i<=10000;i++)
        {
            logs[i] = logs[i/2]+1;      // To be used in Sparse Table Algorithm
        }
    }
    
    void sparsh_table(vector <int> &d)  // Construct a sparse table out of D for RMQ (Range Minimum Query) Optimization
    {
        for (int i=1;i<=n;++i) 
            AND[i][0] = d[i] ;
        for (int r = 1; (1<<r) <= n; ++r) 
        {
            for (int i = 1; i + (1 << r) -1 <= n; ++i) 
            {
                int x = AND[i][r - 1] ;
                int y = AND[i + (1 << (r - 1))][r - 1] ;
                AND[i][r] = x & y ;
            }
        }
    }
    
    int query(int i, int j)
    {
        int l = logs[j-i+1];
        int x = AND[i][l] ; 
        int y = AND[j - (1 << l) + 1][l];
        return (x & y);
    }
    
    
    int get(int ll, int rr, int And) 
    {
        int l = ll, r = rr, lo = 0;
        while (l <= r) 
        {
            int m = (l + r) >> 1 ;
            int tmp = query(ll, m);
            if 
                (tmp < And) r = m - 1;
            else if 
                (tmp > And) l = m + 1;
            else 
            {
                lo = m;
                r = m - 1;
            }
        }
        return lo;
    }
    
    int fun(int in, int im, vector<int> &num, vector<int> &And) 
    {
        // cout << in << " " << im << endl;
        if (in > n) 
        {
            if (im == m-1) 
                return 0;
            return inf;
        }
        int &ret = dp[in][im];
      
        if (~ret) return ret;
      
        int cur = inf;
      
        if ((num[in] & And[im]) == And[im]) 
        {
            cur = min(cur, num[in] - num[in - 1] + fun(in + 1, im, num, And));
        }
        if (im + 1 < m) 
        {
            int l = get(in, n, And[im + 1]);
            // cout << in << " " << im << " == " << l << endl;
            if (l >= in) 
            {
                cur = min(cur, num[l] + fun(l + 1, im + 1, num, And));
            }
        }
        return ret = cur;
    }
    
    int minimumValueSum(vector<int> nums, vector<int> andValues) 
    {
        compute_logs();
        n = nums.size();
        m = andValues.size();
        memset(dp, -1, sizeof(dp));
        nums.insert(nums.begin(), 0);
        sparsh_table(nums);
        int And = (1<<20)-1, ans = inf;
      
        for (int i = 1; i <= n; ++i) 
        {
            And &= nums[i];
            if (And == andValues[0]) 
            {
                ans = min(ans, nums[i] + fun(i + 1, 0, nums, andValues));
            }
        }
      
        if (ans >= inf) ans = -1;
        return ans;
    }
};




