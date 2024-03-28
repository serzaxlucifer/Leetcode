    vector<int> nextLargerNodes(ListNode* head) 
    {
        stack<pair<int, int>> monotone;
        vector<int> answer;
        int iterator = 0;

        while(head != NULL)
        {
            answer.push_back(0);
            while(!monotone.empty() && monotone.top().second < head->val)
            {
                auto it = monotone.top(); monotone.pop();
                answer[it.first] = head->val;
            }

            monotone.push({iterator, head->val});
            head = head->next;
            iterator++;
        }

        return answer;
    }
