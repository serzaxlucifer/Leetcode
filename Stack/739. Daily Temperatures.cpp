    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<pair<int, int>> st;
        vector<int> answer(temperatures.size(), 0);

        for(int i = temperatures.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top().first <= temperatures[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                answer[i] = 0;
            }
            else
            {
                answer[i] = st.top().second - i;
            }
            st.push({temperatures[i], i});
        }

        return answer;

    }
