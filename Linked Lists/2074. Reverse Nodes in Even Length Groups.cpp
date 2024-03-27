    ListNode* reverseEvenLengthGroups(ListNode* head) 
    {
        int groupNum = 0;
        int counter = 0;
        ListNode* cur = head;
        bool breaker = true;
        ListNode* prev = NULL;

        while(cur != NULL)
        {
            groupNum++;
            counter = 0;
            ListNode* startNode = cur;
            ListNode* lastNode = NULL;
            ListNode* prevv = prev;

            while(counter < groupNum && cur)
            {
                counter++;
                if(groupNum % 2 == 0)
                {
                    ListNode* next = cur->next;
                    cur->next = lastNode;
                    lastNode = cur;
                    cur = next;
                }
                else
                {
                    prev = cur;
                    cur = cur->next;
                }
            }

            if(counter % 2 == 0 && groupNum % 2 != 0)
            {
                // reloop and reverse
                prev = prevv;
                cur = prevv->next;
            }

            if(groupNum % 2 == 0)
            {
                startNode->next = cur;
                prevv->next = lastNode;
                prev = startNode;
            }
            if(breaker && groupNum % 2 == 0 && counter % 2 != 0 )
            {
                // reloop and re-reverse it back.
                groupNum--;
                prev = prevv;
                cur = prevv->next;
                breaker = false;
            }
        }

        return head;
    }
