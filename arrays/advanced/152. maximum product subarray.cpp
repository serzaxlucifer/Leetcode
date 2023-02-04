// Initial Approach : O(n)

/*
        The thing here is that there could either be odd or even number of negative signs. So in case of even, a single traversal will give you the result.
        But if there are odd number of those fucking signs. We require traversal from the end as well. If there are no zeros, then it is assured that the max
        subarray will either begin from beginning or from end.
*/

int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int result = INT_MIN;
        int size = nums.size();
        int productSoFar = 1;

        for(int i = 0; i < size; i++)
        {
            productSoFar *= nums[i];
            result = (result < productSoFar) ? productSoFar : result;
            if(productSoFar == 0)
            {
                productSoFar = 1;
            }
        }

        productSoFar = 1;

        for(int i = size-1; i >= 0; i--)                
        {
            productSoFar *= nums[i];
            result = (result < productSoFar) ? productSoFar : result;
            if(productSoFar == 0)
            {
                productSoFar = 1;
            }
        }

        return result;
        
    }

// Let's try to optimize: What do you think might be the optimization here? Well, its simple. Can we combine these two loops into one?? Certainly! Do both stuff in one!



// an amazing solution:
int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int result = INT_MIN;
        int size = nums.size();
        int product = 1;
        int productEnd = 1;

        for(int i = 0; i < size; i++)
        {
            product*= nums[i];
            productEnd*= nums[size-i-1];
            result = max({result, product, productEnd});
            if(product==0) product = 1;
            if(productEnd==0) productEnd = 1;
        }

        return result;
        
    }


//

    int maxProduct(vector<int>& nums) {
       int a=1;
       int b=1;
       int ans=INT_MIN;
       for(auto x:nums){
           int temp1=max({x,a*x,b*x});
           int temp2=min({x,b*x,a*x});

           a=temp1;
           b=temp2;
           ans=max(ans,a);
       }

       return ans;
    }
