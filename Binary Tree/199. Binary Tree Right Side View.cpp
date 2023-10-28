// Using level order traversal
vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        queue<TreeNode*> que;
        vector<int> ans;

        que.push(root);

        while(!que.empty())
        {
            int step = que.size();

            for(int i = 0; i < step; i++)
            {
                TreeNode* current = que.front();
                que.pop();

                if(i == step - 1)
                {
                    ans.push_back(current->val);
                }
                if(current->left)
                {
                    que.push(current->left);
                }
                if(current->right)
                {
                    que.push(current->right);
                }
            }
        }

        return ans;
    }

// Using Recursion

vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;

        recursion(root, 0, ans);

        return ans;
    }

    void recursion(TreeNode* root, int level, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }

        if(level == ans.size())
        {
            ans.push_back(root->val);
        }
        recursion(root->right, level+1, ans);
        recursion(root->left, level+1, ans);
    }
