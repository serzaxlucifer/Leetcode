bool isBalanced(TreeNode* root) 
    {
        return DFS(root) != -1;
    }

    int DFS(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int hL = DFS(root->left);

        if(hL == -1)
        {
            return hL;
        }

        int hR = DFS(root->right);

        if(hR == -1)
        {
            return -1;
        }

        if(abs(hL - hR) > 1)
        {
            return -1;
        }
        return max(hL, hR) + 1;
    }
