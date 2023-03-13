// First Solution:

void deleteNode(ListNode* node) {
        // im so stupid. lets begin now.

        ListNode* last;

        while(node->next != NULL)
        {
            node->val = (node->next)->val;
            last = node;
            node = node->next;
        }

        last->next = NULL;
    }

// Somehow better solutions exist!

void deleteNode(ListNode* node) {                 // PLAIN GENIUS!
        // im so stupid. lets begin now.

        node->val = node->next->val;
        node->next = node->next->next;
    }
