int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }

        int answer = 0;
        queue<pair<TreeNode*, long>> qu;
        qu.push({root, 0});

        while(!qu.empty())
        {
            long curMin = qu.front().second;
            int size = qu.size();
            int left, right;

            for(int i = 0; i < size; i++)
            {
                long cur_id = qu.front().second - curMin; 
                TreeNode* aux = qu.front().first;
                qu.pop();

                if(i == 0) 
                {
                    left = cur_id;
                }

                if(i == size - 1) 
                {
                    right = cur_id;
                }

                if (aux->left)
                {
                    cout << cur_id << endl;
                    qu.push({aux->left, cur_id * 2 + 1});
                }
                if (aux->right)
                {
                    qu.push({aux->right, cur_id * 2 + 2});
                }
            }

            answer = max(answer, right - left + 1);

        }

        return answer;
    }
