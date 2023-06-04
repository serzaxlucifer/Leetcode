// My 1st Iterative Implementation:

ListNode* swapPairs(ListNode* head) 
    {
        // First Implementation-

        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* newHead = head->next;
        ListNode* one = head, *two = head->next, *three;
        ListNode* aux = NULL;
  
  // Keep FOUR pointers: one, two, three and auxiliary.
  // For a linked list, 1 2 3 4 5 6 7 say we're swapping 1 and 2 so the pointers look like: one = 1, two = 2, three = 4, and
  // AUX = 3. Now perform link changes. one->next = three; two->next = one and after this we swap 3 4 so we do change one = aux and two = aux->next and some other case handling for three.

        while(one && one->next)
        {
            if(two->next)
            {
                if(two->next->next)
                {
                    three = two->next->next;
                }
                else
                {
                    three = two->next;
                }
            }
            else
            {
                three = NULL;
            }
            
            one->next = three;
            aux = two->next;
            two->next = one;
            one = aux;

            if(aux)
            {
                two = aux->next;
            }
        }

        return newHead;
    }

// Recursive Solution:

ListNode* swapPairs(ListNode* head) 
    {
        // Recursive Implementation-

        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* next = swapPairs(head->next->next);
        ListNode* one = head;
        ListNode* two = head->next;

        two->next = one;
        one->next = next;

        return two;
        
    }

// (Start swapping from the end!)

