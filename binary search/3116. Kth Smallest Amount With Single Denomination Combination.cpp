// For better explanation, visit: [Below solution is an optimized approach for the same]: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/solutions/5020872/binary-search-inclusion-exclusion-principle-detail-explanation/

class Solution {
long long gcd(long long a, long long b){
        if (a < b) return gcd(b,a);
        if (b == 0) return a;
        return gcd(b,a%b);
    }
public:
    long long findKthSmallest(vector<int> &coins, int k) {
        const int pow[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
        sort(coins.begin(),coins.end());
        if (coins[0] == 1) return k;
        int n = coins.size();
        vector<int> unique;
        for (int i = 0; i < n; i++){
            bool req = true;
            for (int num : unique){
                if (coins[i] % num == 0)
                    req = false;
            }
            if (req) unique.push_back(coins[i]);
        }
        coins = unique;
        n = coins.size();
        vector<long long> add, remove;
        for (int j = 1; j < pow[n]; j++){
            int cnt = 0;
            long long mul = 1;
            for (int i = 0; i < n; i++){
                if ((j & pow[i]) == 0) continue;
                cnt++; mul *= coins[i] / gcd(mul,coins[i]);
            }
            if (cnt % 2) add.push_back(mul);
            else remove.push_back(mul);
        }
        long long min = 1, max = 1ll<<52;
        while (max != min){
            long long mid = (min + max) / 2;
            long long cnt = 0;
            for (long long val : add)
                cnt += mid / val;
            for (long long val : remove)
                cnt -= mid / val;
            if (cnt < k) min = mid+1;
            else max = mid;
        }
        return min;
    }
};
