// Brute Force:

    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int length = 0;
        ListNode* cur = head;
        vector<ListNode*> soln;

        while(cur)
        {
            length++;
            cur = cur->next;
        }

        int nodesPerGroup = length/k;
        int nodesExtra = length % k;

        while(head)
        {
            ListNode* h = head; head = head->next;
            ListNode* original = h;
            int count = nodesPerGroup - 1;
            if(nodesExtra > 0)
            {
                count++;
                nodesExtra--;
            }

            while(count-- && head)
            {
                h->next = head;
                h = h->next;
                head = head->next;
            }
            h->next = NULL;

            soln.push_back(original);
        }

        if(length < k)
        {
            for(int i = length; i < k; i++)
            {
                soln.push_back(NULL);
            }
        }

        return soln;

    }

