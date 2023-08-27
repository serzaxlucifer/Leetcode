bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        stack<int> stack;
        int n = pushed.size();
        int i = 0, j = 0;

        while(i < n)
        {
            if(!stack.empty() and stack.top() == popped[i])
            {
                stack.pop();
                i++;
            }
            else
            {
                if(j == n)
                {
                    return false;
                }
                stack.push(pushed[j]);
                j++;
            }
        }

        return true;
    }
