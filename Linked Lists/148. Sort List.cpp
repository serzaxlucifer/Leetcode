/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
    public:
    ListNode* sortList(ListNode* head) 
    {
        if (head == NULL)
        return head;
    ListNode* start1 = NULL, *end1 = NULL;
    ListNode* start2 = NULL, *end2 = NULL;
    ListNode* prevend = NULL;
    int len = length(head);
 
    for (int gap = 1; gap < len; gap = gap*2) {
        start1 = head;
        while (start1) {
 
            // If this is first iteration
            bool isFirstIter = 0;
            if (start1 == head)
                isFirstIter = 1;
 
            // First part for merging
            int counter = gap;
            end1 = start1;
            while (--counter && end1->next)
                end1 = end1->next;
 
            // Second part for merging
            start2 = end1->next;
            if (!start2)
                break;
            counter = gap;
            end2 = start2;
            while (--counter && end2->next)
                end2 = end2->next;
 
            // To store for next iteration.
            ListNode *temp = end2->next;
 
            // Merging two parts.
            merge(&start1, &end1, &start2, &end2);
 
            // Update head for first iteration, else
            // append after previous list
            if (isFirstIter)
                head = start1;
            else
                prevend->next = start1;
 
            prevend = end2;
            start1 = temp;
        }
        prevend->next = start1;
    }

    return head;
        
    }

int length(ListNode* current)
{
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

void merge(ListNode** start1, ListNode** end1, ListNode** start2, ListNode** end2)
{
 
    // Making sure that first node of second
    // list is higher.
    ListNode* temp = NULL;
    if ((*start1)->val > (*start2)->val) {
        swap(*start1, *start2);
        swap(*end1, *end2);
    }
 
    // Merging remaining nodes
    ListNode* astart = *start1, *aend = *end1;
    ListNode* bstart = *start2, *bend = *end2;
    ListNode* bendnext = (*end2)->next;
    while (astart != aend && bstart != bendnext) {
        if (astart->next->val > bstart->val) {
            temp = bstart->next;
            bstart->next = astart->next;
            astart->next = bstart;
            bstart = temp;
        }
        astart = astart->next;
    }
    if (astart == aend)
        astart->next = bstart;
    else
        *end2 = *end1;
}

};
