int countNodes(TreeNode* root) 
    {
        if(root == NULL)
        {
            return NULL;
        }

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh)
        {
            return (1 << lh) - 1; // 2^h - 1
        }

        // otherwise search left and right

        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);

        return 1 + leftNodes + rightNodes;
    }

    int leftHeight(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        return 1 + leftHeight(root->left);
    }

    int rightHeight(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        return 1 + rightHeight(root->right);
    }
