bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
        {
            return true;
        }

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        // First identify middle node using Hare-Tortoise Algorithm.

        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // now slow points to middle node. reverse the list after it.

        slow->next = reverse(slow->next);
        slow = slow->next;

        while(slow != NULL)
        {
            if(head->val != slow->val)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }

        return true;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = head, *current = head->next, *next;
        head->next = NULL;

        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
