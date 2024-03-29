    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        bool firstPtFound = false;

        int minDistance = INT_MAX;
        int maxDistance = 0;
        int firstPt = 0;
        int lastPt = 0;

        ListNode* prev = head;
        head = head->next;
        int length = 1;

        while(head != NULL)
        {
            length++;
            if(head->next != NULL && ((head->val > prev->val && head->val > head->next->val) || (head->val < prev->val && head->val < head->next->val)))
            {
                // this is a critical point.
                if(!firstPtFound)
                {
                    firstPtFound = true;
                    firstPt = length;
                    lastPt = length;
                }
                else
                {
                    minDistance = min(minDistance, length - lastPt);
                    lastPt = length;
                }
            }

            prev = head;
            head = head->next;
        }

        if(minDistance != INT_MAX)
        {
            maxDistance = lastPt - firstPt;
            return {minDistance, maxDistance};
        }

        return {-1, -1};

        
    }
