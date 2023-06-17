// What needs to be realized here is that we can use Binary Search to improve brute force (one by one remove elements as in removable array and check if 'p' is still a subsequence of 's') into
// logarithmic time complexity. We need to count fro beginning of removables vector. That means try checking middle first. If all satisfy till middle, we don't need to check indexes before it.

class Solution {    // [ 93% Runtime ]
public:
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        int maxRemovals = 0;

        int left = 0, end = removable.size();
        int mid = (left + end) / 2;

        while(left <= end)
        {
            if(isSubsequence(s, p, mid, removable))
            {
                left = mid + 1;
                maxRemovals = mid;
            }
            else
            {
                end = mid - 1;
            }
            mid = (left + end) / 2;
        }

        return maxRemovals;
    }

    bool isSubsequence(string s, string p, int index, vector<int>& removable)
    {
        int s1 = s.length();
        int s2 = p.length();
        int a = 0, b = 0;

        for(int i = 0; i < index; i++)
        {
            s[removable[i]] = '$';
        }

        while(a < s1 && b < s2)
        {
            if(s[a] == p[b])
            {
                b++;
            }
            a++;
        }

        return b == s2;
    }
};




