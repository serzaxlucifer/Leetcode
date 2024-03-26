    ListNode* partition(ListNode* head, int x) 
    {

        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode* h1 = head1, *h2 = head2;

        while(head)
        {
            if(head->val < x)
            {
                head1->next = head;
                head1 = head1->next;
            }
            else
            {
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
        }

        head1->next = h2->next;
        head2->next = NULL;
        return h1->next;
    }
