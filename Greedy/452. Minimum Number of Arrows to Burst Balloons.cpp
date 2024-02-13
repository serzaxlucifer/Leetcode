bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int count = 1;
        int size = points.size();
        int slotEnd = points[0][1];

        for(int i = 1; i < size; i++)
        {
            if(points[i][0] > slotEnd)
            {
                count++;
                slotEnd = points[i][1];
            }
        }

        return count;
    }
};
