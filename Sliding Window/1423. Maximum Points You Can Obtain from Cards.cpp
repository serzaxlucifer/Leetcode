// 1st approach:

int maxScore(vector<int>& cardPoints, int k) 
    {
        // Sliding Window

        int maxPts = 0;
        int m = k;

        for(int i = 0; i < m; i++)
        {
            maxPts += cardPoints[i];
        }

        int pts = maxPts;

        for(int i = cardPoints.size()-1; i >= 0 && k > 0; i--)
        {
            pts -= cardPoints[m -(cardPoints.size()-i)];
            pts += cardPoints[i];
            k--;

            maxPts = max(maxPts, pts);
        }

        return maxPts;
    }


