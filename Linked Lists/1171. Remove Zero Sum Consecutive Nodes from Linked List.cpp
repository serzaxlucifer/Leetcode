// CODE:

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* start = front;

        while (start != nullptr) {
            int prefixSum = 0;
            ListNode* end = start->next;

            while (end != nullptr) {
                // Add end's value to the prefix sum
                prefixSum += end->val;
                // Delete zero sum consecutive sequence 
                // by setting node before sequence to node after
                if (prefixSum == 0) {
                    start->next = end->next;
                }
                end = end->next;
            }

            start = start->next;
        }
        return front->next;
    }
};

// Optimizing:

    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;

        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;

        while (current != NULL) 
        {
            prefixSum += current->val;

            if(prefixSumToNode.find(prefixSum) != prefixSumToNode.end())
            {
                ListNode* prev = prefixSumToNode[prefixSum];
                current = prev->next;

                int p = prefixSum + current->val;
                while (p != prefixSum) 
                {
                    prefixSumToNode.erase(p);
                    current = current->next;
                    p += current->val;
                }

                prev->next = current->next;
            } 
            else 
            {
                prefixSumToNode[prefixSum] = current;
            }

            current = current->next;
        }

        return front->next;
    }
