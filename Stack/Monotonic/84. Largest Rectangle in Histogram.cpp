    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> monotone;

        int maxA = 0;
        int size = heights.size();

        for(int i = 0; i <= size; i++)
        {
            while(!monotone.empty() && (i == size || heights[monotone.top()] >= heights[i]))
            {
                int height = heights[monotone.top()]; monotone.pop();
                int width;
                if(monotone.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - monotone.top() - 1;
                }

                maxA = max(maxA, width*height);
            }

            monotone.push(i);
        }

        return maxA;
    }

// Reference: https://youtu.be/X0X6G-eWgQ8?si=7Xuc1T7NJOl6KSIh --> https://youtu.be/jC_cWLy7jSI?si=nq52S_HkPJTUz3Xu
