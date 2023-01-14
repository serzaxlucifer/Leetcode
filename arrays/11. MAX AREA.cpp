int maxArea(vector<int>& height) {
        // initial goal is to solve in a single traversal. Improvisations can be done later but this is the base to synthesize the algorithm on.

        int maxArea = 0;
        int auxArea = 0;
        int auxWidth = 0;

        for(int i = 0, j = height.size() - 1; i < j;)
        {
            auxWidth = j-i;
            auxArea = auxWidth * min(height[i], height[j]);
            if(auxArea > maxArea)
            {
                maxArea = auxArea;
            }
            if(height[i] <= height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxArea;

    }
