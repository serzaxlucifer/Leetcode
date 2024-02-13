class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> newInt;
        int size = intervals.size();

        int iterator = 0;
        while(iterator < size && intervals[iterator][1] < newInterval[0])
        {
            newInt.push_back(intervals[iterator++]);
        }

        // Now here it comes! Identify overlaps.

        while(iterator < size && intervals[iterator][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[iterator][0]);
            newInterval[1] = max(newInterval[1], intervals[iterator][1]);
            iterator++;
        }

        newInt.push_back(newInterval);

        while(iterator < size)
        {
            newInt.push_back(intervals[iterator++]);
        }

        return newInt;
    }
};

// Note that you could use Binary Search to find lower and upper bounds and put it there in place as well.

