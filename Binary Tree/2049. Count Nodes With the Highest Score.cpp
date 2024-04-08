class Solution {
public:
    int subTreeCalculator(vector<int>& subtreesLeft, vector<int>& subtreesRight, vector<int>& lC, vector<int>& rC, int node)
    {
        if(node == -1)
        {
            return 0;
        }

        int left = subTreeCalculator(subtreesLeft, subtreesRight, lC, rC, lC[node]);
        int right = subTreeCalculator(subtreesLeft, subtreesRight, lC, rC, rC[node]);
        subtreesLeft[node] = left;
        subtreesRight[node] = right;

        return 1 + left + right;
    }

    int countHighestScoreNodes(vector<int>& parents) 
    {
        int size = parents.size();
        vector<int> lC(size, -1);
        vector<int> rC(size, -1);
        vector<int> subtreesLeft(size, -1);
        vector<int> subtreesRight(size, -1);

        for(int i = 1; i < size; i++)
        {
            int parent = parents[i];
            if(lC[parent] == -1)
            {
                lC[parent] = i;
            }
            else
            {
                rC[parent] = i;
            }
        }

        subTreeCalculator(subtreesLeft, subtreesRight, lC, rC, 0);

        long long maximum = 0;
        int count = 0;

        for(int i = 0; i < size; i++)
        {
            int left = subtreesLeft[i];
            int right = subtreesRight[i];

            int total = 1 + left + right;
            int upper = 1;

            if(i != 0)
            {
                upper = 1 + subtreesLeft[0] + subtreesRight[0] - total;
            }

            left = left == 0 ? 1 : left;
            right = right == 0 ? 1 : right;

            long long curMax = (long long)upper*left*right;

            if(curMax == maximum)
            {
                count++;
            }
            else if(curMax > maximum)
            {
                count = 1;
                maximum = curMax;
            }
        }

        return count;
         
    }
};
