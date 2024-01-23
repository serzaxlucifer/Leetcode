ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) pq.push(lists[i]);
        }
        while(!pq.empty()) {
            ListNode *temp = pq.top();
            pq.pop();
            tail -> next = temp;
            tail = temp;
            if(temp -> next != NULL) pq.push(temp -> next);
        }
        return dummy -> next;
    }
