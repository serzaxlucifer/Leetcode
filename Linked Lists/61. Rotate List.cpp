// My 1st implementation:

ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL)
        {
            return head;
        }
        int nodeCount = 0;

        ListNode* slow = head, *fast = head, *aux = head;

        for(int i = 1; i <= k; i++)
        {
            nodeCount++;
            fast = fast->next;

            if(fast == NULL)
            {
                k = (k) % nodeCount;
                i = 0;
                fast = head;
            }
        }

        if(k == 0)
        {
            return head;
        }
        
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Now perform link changes

        aux = slow->next;
        slow->next = NULL;
        fast->next = head;

        return aux;
    }

// Runtime: beats 96%

