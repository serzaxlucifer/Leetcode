vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }

        queue<TreeNode*> que;
        vector<vector<int>> ans;

        que.push(root);
        bool direction = true;

        while(!que.empty())
        {
            int step = que.size();

            vector<int> level(step);
            for(int i = 0; i < step; i++)
            {
                TreeNode* current = que.front();
                que.pop();

                // level.push_back(current->val);
                int index = direction ? i : step - i - 1;
                level[index] = current->val;

                if(current->left)
                {
                    que.push(current->left);
                }
                if(current->right)
                {
                    que.push(current->right);
                }
            }

            direction = !direction;

            ans.push_back(level);
        }

        return ans;
    }
