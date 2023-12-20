bool findTarget(TreeNode* root, int k) 
    {
        unordered_set<int> set;
        return digger(root, k, set);
    }

    bool digger(TreeNode* root, int k, unordered_set<int>& set)
    {
        if(root == NULL)
        {
            return false;
        }

        if(set.find(k - root->val) != set.end())
        {
            return true;
        }
        set.insert(root->val);

        return digger(root->left, k, set) || digger(root->right, k, set);
    }
