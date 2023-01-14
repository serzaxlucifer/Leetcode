// This question states that you're given an array that contains N elements. You're required to find "UNIQUE" k-sets (arrays of k elements) from the given array such that the sum of the k elements is equal to a given target value. Return all such possible k-sets in an array. By arrays, we mean vectors. 
// To this question, there exists a recursive approach whose time complexity will be: O(n^(k-1)). Iteration is not possible for me as k is unknown. Recursion seems to be the best bet!

// Problems exist with this solution.
vector<vector<int>> sumMainProcessor(vector<int>& nums, int target, int k)
{
  sort(nums.begin(), nums.end());
  return kSum(nums, 0, target, k);
}

vector<vector<int>> kSum(vector<int>& nums, int start, int target, int k)
{
  vector<vector<int>> result;
  if(start == nums.size())
  {
    return result;
  }
  if(nums[start] > (target/k) || (target/k) > nums.back()) 
  {
    return res;     // further pruning the algorithm.
  }
  
  if(k == 2)
  {
    // perform 2Sum
    int start = start; 
    int end = nums.size() - 1;
    
    while (start < end) 
    {
      int curr_sum = nums[start] + nums[end];
      if (curr_sum < target || (start > start && nums[start] == nums[start - 1])) 
      {
        ++start;
      } 
      else if (curr_sum > target || (end < nums.size() - 1 && nums[end] == nums[end + 1]))
      {
        --end;
      } 
      else 
      {
        result.push_back({ nums[start++], nums[end--] });
      }
    }
                                                           
    return result;
  }
  
  for(int i = start; i < nums.size(); i++)
  {
    if(i == start || nums[i-1] != nums[i])
    {
      for(vector<int>& possible : kSum(nums, i+1,target - nums[i],k-1))
      {
        result.push_back({nums[i]});
        result.back().insert(result.back().end(), possible.begin(), possible.end());
      }
    }
    // else skip this value!
  }
  return result;
}

// ABSOLUTE CORRECT:

vector<vector<int>> sumMainProcessor(vector<int>& nums, int target, int k)
{
  sort(nums.begin(), nums.end());
  return kSum(nums, target,0, k);
}

vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> res;
        
        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }
        
        // There are k remaining values to add to the sum. The 
        // average of these values is at least target / k.
        long long average_value = target / k;
        
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest 
        // value in nums is smaller than target / k.
        if  (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }
            
        if (k == 2) {
            return twoSum(nums, target, start);
        }
    
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
                                            
        return res;
    }
	
    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = int(nums.size()) - 1;
    
        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }
                                                           
        return res;
    }
