// Approach:  Resource Used: https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/

/*

We will use two pointers with different steps forward. The process is as follows:-

1. We will take two pointers, namely fast and slow. Fast pointer takes 2 steps ahead and slow pointer takes 1 points ahead.
2. Iterate through the list until the fast pointer is equal to NULL. This is because NULL indicates that there is no cycle present in the given list.
3. Cycle can be detected when fast and slow pointers collide.

*/

// Intriguing Question: What should happen IF we take speed of fast pointer as 3 times that of slow pointer. I ran the code with speeds and the runtime comparison is given below.

// 2x Fast Pointer Speed:

bool hasCycle(ListNode *head) {
        // Tortoise-Hare-Approach

        if(head == NULL)
        return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return true;
            }
        }

        return false;
    }
// runtime on try 1: 66% - 11ms
// runtime on try 2: 99.8% - 3ms

// 3x Speed
bool hasCycle(ListNode *head) {
        // Tortoise-Hare-Approach

        if(head == NULL)
        return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next && fast->next->next->next)
        {
            slow = slow->next;
            fast = fast->next->next->next;
            if(slow == fast)
            {
                return true;
            }
        }

        return false;
    }

// Runtime: 66% and 44% on try 2 -- computations in while loop increase which increase the time overhead a lot. This is thus performance-reducing and not optimal.

// Another version of 2x speed

bool hasCycle(ListNode *head) {
        // Tortoise-Hare-Approach

        if(head == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast)
        {
            if(fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }


