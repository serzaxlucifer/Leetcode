// 2 pointer approach:

vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
        vector<int> answer;

        while(start < end)
        {
            if(numbers[end] + numbers[start] == target)
            {
                answer.emplace_back(start+1);
                answer.emplace_back(end+1);
                break;
            }
            else if(numbers[end] + numbers[start] > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return answer;
    }

// 2 pointer approach + Binary Search Optimization (not very efficient if I follow runtime for some reason):

vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
        vector<int> answer;
        int mid;

        while(start < end)
        {
            mid = start + (end - start)/2;
            if(numbers[start] + numbers[end] == target)
            {
                answer.emplace_back(start+1);
                answer.emplace_back(end+1);
                return answer;
            }
            else if(numbers[end] + numbers[start] > target)
            {
                if(numbers[mid] + numbers[start] >= target)
                {
                    end = mid;
                }
                else
                {
                    end--;
                }
            }
            else
            {
                if(numbers[mid] + numbers[end] <= target)
                {
                    start = mid;
                }
                else
                {
                    start++;
                }
            }
        }

        return answer;
    }
