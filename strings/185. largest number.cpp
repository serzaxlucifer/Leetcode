// First Solution (Involves a beautiful use of Lambda Sorting algorithm)

    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto i:nums)
        {
            arr.push_back(to_string(i));
        }

        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2 > s2+s1; });    // customized sort algorithm
        string result;

        for(auto i : arr)
        {
            result += i;
        }

        while(result[0] == '0' && result.length() > 1)
        {
            result.erase(0, 1);
        }
        return result;
    }

// Next Solution: (same but without lambda expression)

bool solve(string a, string b){
        return a+b>b+a;
}

string largestNumber(vector<int>& nums) 
{
        vector<string> v;
        for(auto it: nums) v.push_back(to_string(it));
        sort(v.begin(), v.end(), solve);
        string ans = "";
        for(auto it: v){
            ans+=it;
        }
        while(ans.length() > 1 and ans[0] == '0')
            ans.erase(0,1);
        return ans;
    }

// Next:
class Solution
{
static bool compare(int& a, int& b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return (s1+s2) > (s2+s1);
    }
    string largestNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end(), compare);

        string result;

        for(auto i : nums)
        {
            result += to_string(i);
        }

        while(result[0] == '0' && result.length() > 1)
        {
            result.erase(0, 1);
        }
        return result;
    }
};


