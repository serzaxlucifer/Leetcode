// an amazing solution:

int maxProduct(vector<int>& nums) {
        int prod=1;
        int maxi=INT_MIN;
        for(int i : nums){
            prod=prod*i;
            maxi=max(maxi,prod);
            if(prod==0){
                prod=1;
            }
        }
        prod=1;
        reverse(nums.begin(),nums.end());
        for(int i : nums){
            prod=prod*i;
            maxi=max(maxi,prod);
            if(prod==0){
                prod=1;
            }
        }
        return maxi;
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
