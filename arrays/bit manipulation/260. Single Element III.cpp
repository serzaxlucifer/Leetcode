// MY SOLN:
vector<int> singleNumber(vector<int>& nums) 
    {
        int xorr = 0;
        for(int i : nums)
        {
            xorr ^= i;
            if(i == INT_MIN)
            {
                return {0, INT_MIN};
            }
        }

        

        xorr &= -xorr;
        vector<int> res(2, 0);

        for(int i : nums)
        {
            if((i & xorr) == 0)
            {
                res[0] ^= i;
            }
            else
            {
                res[1] ^= i;
            }
        }

        return res;
    }

// Best Possible Solution:

vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(auto x:nums)
        {
            xr = xr^x;
        }
        int sn = __builtin_ctz(xr);
        sn = (1<<sn);
        int res=0;
        // cout<<xr<<" "<<sn<<" u ";
        for(auto x:nums)
        {
            if((x&sn)!=0)
            {
                // cout<<x<<" o ";
                res = res^x;
            }
        }
        return {res,res^xr};
    }
