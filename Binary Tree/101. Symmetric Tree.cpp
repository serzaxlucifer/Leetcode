bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
        {
            return true;
        }

        return symmetricChecker(root->left, root->right);
    }

    bool symmetricChecker(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
        {
            return true;
        }
        else if(right == NULL || left == NULL)
        {
            return false;
        }

        if(left->val != right->val)
        {
            return false;
        }

        return symmetricChecker(left->left, right->right) && symmetricChecker(left->right, right->left);
    }
