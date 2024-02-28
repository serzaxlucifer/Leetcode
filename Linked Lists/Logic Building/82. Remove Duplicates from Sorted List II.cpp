    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL)
        {
            return NULL;
        }

        ListNode* cur = head;
        ListNode* prev = new ListNode(0, head);
        ListNode* newHead = prev;

        while(cur != NULL)
        {
            while(cur->next != NULL && cur->val == cur->next->val)
            {
                cur = cur->next;
            }

            if(prev->next == cur)
            {
                prev = prev->next;
            }
            else
            {
                prev->next = cur->next;
            }

            cur = cur->next;
        }
        

        return newHead->next;
    }
