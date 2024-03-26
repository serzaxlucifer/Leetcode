    Node* flatten(Node* head) 
    {
        recurse(head);
        return head;    
    }

    Node* recurse(Node* head)
    {
        if(head == NULL)
        {
            return NULL;
        }

        Node* traverser = head, *prev = NULL;

        while(head != NULL)
        {
            Node* next = head->next;

            if(head->child != NULL)
            {
                head->next = head->child;
                head->child->prev = head;
                traverser = recurse(head->child);
                head->child = NULL;
                traverser->next = next;
                if(next)
                    next->prev = traverser;
            }

            prev = traverser;
            traverser = traverser->next;
            head = next;
        }

        return prev;
    }
