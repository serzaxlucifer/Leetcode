class Solution {
public:

    static bool comp(vector<int> &a,vector<int> &b) 
    {
	    return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.size() == 0)
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), comp);
        int prevEnd = intervals[0][1];
        int count = 0;

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] >= prevEnd)
            {
                prevEnd = intervals[i][1];
            }
            else
            {
                count++;
            }
        }

        return count;
    }
};
