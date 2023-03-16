ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }

        ListNode* auxEven = head->next, *odd = head, *evenHead = head->next;

        while(auxEven && auxEven->next)
        {
            odd->next = auxEven->next;
            odd = odd->next;
            auxEven->next = odd->next;
            auxEven = auxEven->next;
        }
        odd->next = evenHead;

        return head;
    }
