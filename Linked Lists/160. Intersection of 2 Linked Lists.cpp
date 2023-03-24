ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;

        ListNode* a = headA, *b = headB;

        while(a != NULL)
        {
            lenA++;
            a=a->next;
        }
        while(b != NULL)
        {
            lenB++;
            b=b->next;
        }

        int diff  = lenA - lenB;


        if(diff >= 0)
        {
            while(diff != 0)
            {
                headA = headA->next;
                diff--;
            }
        }
        else
        {
            while(diff != 0)
            {
                headB = headB->next;
                diff++;
            }
        }

        while(headA && headB)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
        
    }
