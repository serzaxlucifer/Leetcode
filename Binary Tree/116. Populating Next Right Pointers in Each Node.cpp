// My brute force includes a BFS traversal.

Node* connect(Node* root) 
    {
        // Let's try using a BFS approach. Run time: 90% on 2nd run.

        if(root == NULL)
        {
            return root;
        }

        Node* queue[4096];        // 2^12 - 1 requires 4095 indexes.
        int front = 0;
        int end = 0;

        queue[end++] = root;

        Node* previous = NULL, *current;


        while(end != front)
        {
            int frontierSize = end - front;

            while(frontierSize--)
            {
                if(!previous)
                {
                    previous = queue[front++];
                    current = previous;
                }
                else
                {
                    previous = current;
                    current = queue[front++];
                    previous->next = current;
                }
                if(current->left)
                {
                    queue[end++] = current->left;
                }
                if(current->right)
                {
                    queue[end++] = current->right;
                }
            }

            current->next = NULL;
            previous = NULL;
        }

        return root;
    }

// Now let's explore other possibilities. And more space optimization is needed in Follow-up challenge.

// This is another approach which runs in O(1) Space! It's truly baffling how this one unfolds.
// How do I know a new level start or what is the start of a new level? The left child of the first head node on the upper level.
// This approach involves joining the child nodes, then traversing the child node linked list connecting their children and so on. Utilizing this,
// you don't need a queue!

    Node* connect(Node* root) 
    {

        Node* head = root;

        for(head = root; head != NULL; head = head->left)
        {
            if(head->left == NULL)  // start of a new level that is already connected. We connect the level below it if it exists.
            {
                return root;
            }

            Node* previous = NULL, *current = head;

            while(current != NULL)
            {
                if(previous != NULL)
                {
                    previous->right->next = current->left;
                }
                current->left->next = current->right;

                previous = current;
                current = current->next;
            }
        }

        return root;
    }

// Let's also talk of a recursive approach to develop our recursion skills. How do we do this using recursion?
Node* connect(Node* root)
{
        if(root==NULL) 
        {
          return NULL;
        }
  
        Node* lChild = root->left, *rChild = root->right;
  
        if(lChild)
        {
            lChild->next = rChild;
            if(root->next != NULL) 
            {
              rChild->next = root->next->left;
            }
            
            connect(lChild);
            connect(rChild);
        }
  
        /* since it is perfect binary tree,if left child does not exist, we are at
        (i.e. curr is)first leaf node, at the last level so we return */
        return root;
  
}
