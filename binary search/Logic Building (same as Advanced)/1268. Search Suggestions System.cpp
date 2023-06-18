// Realize the utilization of Binary Search. When you're sorting, you always have Binary Search in your arsenal.

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) // 90% runtime O(NlogN + MlogN)
    {
        sort(products.begin(), products.end());         // arrange lexicographically.

        vector<vector<string>> answer;

        int size = products.size();
        int start = 0;
        string prefix;

        for(auto &c : searchWord)
        {
            prefix += c;
            answer.push_back({}); 
            int lb = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();  // FIND first occurence of suitable match. And search for 3 coming matches. Next searches will begin from here.

            for(int i = lb; i < min(lb + 3, size) && !products[i].compare(0, prefix.length(), prefix); i++)
            {
                answer.back().push_back(products[i]);
            }

            start = lb;
        }

        return answer;
    }

// I also wrote my own function for lower_bound() but it fails on test case 39 for some reason and the test case 
// very big to find the fault. If you can find the fault, here it is (seems right to me):

int lower_bound(vector<string>& products, int start, int end, string prefix)    
{
    int mid = (start + end) / 2;
    int prefLen = prefix.length();
    int i = 0;
    bool flag = true;

    while(start < end)
    {
        flag = true;
        for(i = 0; i < min(prefLen, products[mid].length()); i++)
        {
            
            if(products[mid][i] < prefix[i])
            {
                flag = false;
                start = mid + 1;
                break;
            }
            else if(products[mid][i] > prefix[i])
            {
                flag = false;
                end = mid - 1;
                break;
            }
        }

        // equality observed.
        if(flag)
        {
            end = mid;
        }
        mid = (start + end) / 2;

    }

    return start;
}


// Other ways to implement? You can replace Binary Search with 2-pointer approach.

class Solution {    // courtesy of https://leetcode.com/problems/search-suggestions-system/solutions/1242823/c-python-3-solutions-clean-concise/
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) 
    {
        int n = products.size();
        sort(products.begin(), products.end());  // Sort by increasing lexicographically order of products.
        vector<vector<string>> ans;
        int startIdx = 0, endIdx = n - 1;
      
        for (int i = 0; i < searchWord.length(); i++) 
        {
            while (startIdx <= endIdx && (i >= products[startIdx].size() || products[startIdx][i] < searchWord[i]))
                startIdx++;
            while (startIdx <= endIdx && (i >= products[endIdx].size() || products[endIdx][i] > searchWord[i]))
                endIdx--;

            ans.push_back({});
            for (int j = startIdx; j < min(startIdx + 3, endIdx + 1); ++j) 
            {
                ans.back().push_back(products[j]);
            }
        }
        return ans;
    }
};

// Time complexity: O(NlogN + M)

// ------ There is another concept called 'Tries' (comes from the word 'reTRIEval') for pattern matching! You can explore this
// concept at GeeksForGeeks (GFG).

// Read: https://leetcode.com/problems/search-suggestions-system/solutions/1242823/c-python-3-solutions-clean-concise/
// Read: https://leetcode.com/problems/search-suggestions-system/solutions/2167835/a-more-intuitive-solution-java-explained/

