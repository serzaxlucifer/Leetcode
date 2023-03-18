ListNode* deleteMiddle(ListNode* head) {
        // easy to do!

        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }

        ListNode* slow = head, *fast = head, *midPrev = head;

        while(fast && fast->next)
        {
            midPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        midPrev->next = slow->next;

        return head;
    }
