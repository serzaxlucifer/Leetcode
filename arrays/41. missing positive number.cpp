// my initial solution (not optimized for time):
int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());         // TC: O(logn)
        int ans = 1;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            if(nums[i]==ans) ans++;
        }

        return ans;
    }

// now this implementation uses a vector (mapper).


// the challenge is to do in TC: O(n) and SC: O(1)
// meaning Index Mapping and logical reasoning!
int firstMissingPositive(vector<int>& nums) {
        // index mapping!
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            while(nums[i] >= 1 && nums[i] <= size-1 && nums[i] != nums[nums[i]-1])
            {
                int temp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[temp-1] = temp;
            }
        }

        for(int i = 0; i < size; i++)
        {
            if(nums[i]!=i+1)
            {
                return (i+1);
            }
        }

        return size+1;
    }

// best:
// To map, negating the numbers is also an approach here.
{
bool flag = false;
        int n = nums.size();
        for(int num : nums){
            if(num==1){
                flag=true;
            }
        }
        if(!flag) return 1;
        
        if(n == 1) return 2;
        
        for(int i=0; i<n; i++){
            if(nums[i]<=0 || nums[i]>n){
                nums[i] = 1;
            }
        }
        for(int i=0; i<n; i++){
            int x = abs(nums[i]);
            if(nums[x-1]>0) nums[x-1]*=-1;
        }
        for(int i =0; i<n; i++){
            if(nums[i]>0) return i+1; 
        }
        return n+1;
}
