// my first solution:   // runtime: 83%

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a1 = head;
        ListNode* a2 = head;
        int count = 0;

        while(a2->next != NULL)
        {
            if(count >=n )
            {
                a1 = a1->next;
            }
            a2 = a2->next;
            count++;
        }

        if(a1->next == NULL)
        {
            return NULL;
        }
        if(count < n)
        {
            return a1->next;
        }

        ListNode* finaln = a1->next->next;
        a1->next = finaln;

        return head;
    }

// To remove comparisons, add a dummy node in beginning.

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
