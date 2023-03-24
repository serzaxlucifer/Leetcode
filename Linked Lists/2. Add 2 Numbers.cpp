ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* output  = new ListNode(0, NULL), *curr = output;

        int carry = 0;
        
        while(l1 != NULL || l2 != NULL || carry)
        {
            int v1 = 0, v2 = 0;
            if(l1)
            {
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                v2 = l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode((v1+v2+carry) % 10, NULL);
            carry = (v1+v2+carry)/10;
            curr = curr->next;
        }
        return output->next;
    }
