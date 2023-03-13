// o(N) Time and Space

ListNode* middleNode(ListNode* head) {
        // Only O(n) time allowed! How do we use space at our disposal??

        vector<ListNode*> vec;      // save a second traversal!
        while(head!=NULL)
        {
            vec.emplace_back(head);
            head = head->next;
        }

        return vec[vec.size()/2];
    }

// O(n) time and O(1) space // Genius Solution

ListNode* middleNode(ListNode* head) {
        // Only O(n) time allowed! 

        ListNode* slow = head;
        ListNode* fast = head;      // traverse twice as fast as slow.

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }






