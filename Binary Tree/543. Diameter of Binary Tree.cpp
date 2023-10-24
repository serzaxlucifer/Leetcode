// What if we add height of left and right subtrees? It won't work since the bigger path may be in some subtree itself!
// HINT: POST ORDER TRAVERSAL!



int diameterOfBinaryTree(TreeNode* root) 
    {
        int dia = 0;
        diameter(dia, root);
        return dia;
    }

    int diameter(int& dia, TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int lh = diameter(dia, root->left);
        int rh = diameter(dia, root->right);

        dia = max(dia, lh + rh);

        return 1 + max(lh, rh);
    }

