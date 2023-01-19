// Method 1:
int triangularSum(vector<int>& nums) {
        int size=nums.size();
        int arr[size];
        
        for(int i=0;i<size;i++){
            arr[i]=nums[i];
        }
        
        while(size>1){
            for(int i=0;i<size-1;i++){
                arr[i]=(arr[i]+arr[i+1])%10;
            }
            size--;
        }
        return arr[0];
    }

// Method 2: (Least RunTIME)
int c[1001][1001] = {}, n = 1;
class Solution {
public:
int triangularSum(vector<int>& nums) {
    for (; n <= nums.size(); ++n) // compute once for all test cases.
        for (int r = 0; r < n; ++r) 
            c[n][r] = r == 0 ? 1 : (c[n - 1][r - 1] + c[n - 1][r]) % 10;
    return inner_product(begin(nums), end(nums), begin(c[nums.size()]), 0) % 10;
}
};

// Method 3:
int triangularSum(vector<int>& nums) {
        for (auto it = nums.begin(), end = nums.end(); it != end; ++it) {
            adjacent_difference(it, end, it, [](auto a, auto b) { return (a + b) % 10; });
        }
        return nums.back();
    }









