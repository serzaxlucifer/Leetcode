    int maxPathSum(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        int maxRef = INT_MIN;
        helper(root, maxRef);

        return maxRef;
    }

    int helper(TreeNode* root, int &maxRef)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftPathSum = max(0, helper(root->left, maxRef));
        int rightPathSum = max(0, helper(root->right, maxRef));

        maxRef = max(maxRef, root->val + leftPathSum + rightPathSum);
        return root->val + max(leftPathSum, rightPathSum);
    }
