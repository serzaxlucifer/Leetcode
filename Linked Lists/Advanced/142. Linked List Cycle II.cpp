ListNode *detectCycle(ListNode *head) {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (head == NULL || head->next == NULL)
        return NULL;
    
        ListNode *slow  = head;
        ListNode *fast  = head;
        ListNode *entry = head;
    
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {                      // there is a cycle
                while(slow != entry) {               // find the entry location
                    slow  = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;                                 // there is no cycle

    }

// Video for explanation for why the entry pointer and slow pointer collide at starting pt --> https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=37

