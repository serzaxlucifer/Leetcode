// 1st Implementation: (Intuitive Recursive Approach!)

ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL)
        {
            return head;
        }

        // Let's try a recursive approach first.
        int counter = 0;

        ListNode* traversal = head;
        ListNode* next = NULL;

        while(traversal)
        {
            traversal = traversal->next;
            counter++;

            if(counter == k)
            {
                next = reverseKGroup(traversal, k);
                head = reverse(head, k, next);
                break;
            }
        }

        return head;

    }

    ListNode* reverse(ListNode* head, int k, ListNode* lastLink)
    {
        ListNode* current = head, *previous = head, *next = NULL;
        int counter = 0;

        while(counter < k)
        {
            next = current->next;
            current->next = lastLink;
            lastLink = current;
            current = next;
            counter++;
        }

        return lastLink;

    }

// Can we optimize further? Well for that, you can obviously devise an iterative solution
// that doesn't involve recursion stack to save space.

