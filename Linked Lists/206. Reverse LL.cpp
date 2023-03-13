ListNode* reverseList(ListNode* head) {
        
        ListNode* eq = NULL;
        ListNode* next;

        while(head)
        {
            next = head->next;
            head->next = eq;
            eq = head;
            head = next;
        }

        return eq;
    }
