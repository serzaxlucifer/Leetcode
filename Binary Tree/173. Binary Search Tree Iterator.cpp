// My first solution (Time: 86%, Space: 95%) ~ O(1) time (avg.) and O(h) space

class BSTIterator 
{
    stack<TreeNode*> trace;
    TreeNode* iterator;
    int val;

    public:
    BSTIterator(TreeNode* root) 
    {
        TreeNode* temp = root;
        trace.push(root);

        while(temp->left != NULL)
        {
            trace.push(temp->left);
            temp = temp->left;
        }

        TreeNode* beg = new TreeNode(-1);
        beg->right = temp;
        iterator = beg;
        val = -1;
    }
    
    int next() 
    {
        if(iterator->val == -1)
        {
            iterator = iterator->right;
            val = iterator->val;
            trace.pop();
            return val;
        }

        if(iterator->right)
        {
            iterator = iterator->right;
            trace.push(iterator);
            while(iterator->left)
            {
                trace.push(iterator->left);
                iterator = iterator->left;
            }
        }

        if(iterator->left && iterator->left->val > val)
        {
            while(iterator->left)
            {
                trace.push(iterator->left);
                iterator = iterator->left;
            }

            val = iterator->val;
            return val;
        }

        while(trace.top()->val <= val)
        {
            trace.pop();
        }

        iterator = trace.top();
        trace.pop();
        val = iterator->val;
        return val;
    }
    
    bool hasNext() 
    {
        return iterator->right != NULL || !trace.empty();
    }
};

// ------

class BSTIterator {
    private: 
             stack<TreeNode*> myStack;
             
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmp = myStack.top();
        myStack.pop();

        pushAll(tmp->right);

        return tmp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

    private:
    void pushAll(TreeNode* node)
             {
                 while(node)
                 {
                     myStack.push(node);
                     node = node->left;
                 }
             }
};
