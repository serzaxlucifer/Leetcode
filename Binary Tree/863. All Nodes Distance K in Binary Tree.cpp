class Solution {      // 82% Runtime
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if(root == NULL)
        {
            return {};
        }
        vector<int> answer;

        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        parent[root] = NULL;
        queue<TreeNode*> tracker;

        generate_parent_trace(root, target, parent);

        tracker.push(target);   // stop the queue when it has the required nodes in it.
        int distance = 0;
        bool originReached = false;

        while(!tracker.empty())
        {
            if(distance++ == k)
            {
                break;
            }
            int size = tracker.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode* popped = tracker.front(); tracker.pop();

                if(popped->left && !visited[popped->left])
                {
                    visited[popped->left] = true;
                    tracker.push(popped->left);
                }
                if(popped->right && !visited[popped->right])
                {
                    visited[popped->right] = true;
                    tracker.push(popped->right);
                }
                if(!originReached && parent[popped] && !visited[parent[popped]])
                {
                    visited[parent[popped]] = true;
                    tracker.push(parent[popped]);
                    if(parent[popped] == root)
                    {
                        originReached = true;
                    }
                }
            }

        }

        while(!tracker.empty())
        {
            TreeNode* popped = tracker.front(); tracker.pop();
            answer.push_back(popped->val);
        }

        return answer;
        
    }

    void generate_parent_trace(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& map)
    {
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty())
        {
            TreeNode* current = queue.front(); queue.pop();
            // if(current == target)
            // {
            //     break;
            // }    // unnecessary information.

            if(current->left != NULL)
            {
                map[current->left] = current;
                queue.push(current->left);
            }
            if(current->right != NULL)
            {
                map[current->right] = current;
                queue.push(current->right);
            }
        }
    }
};

// Recursive:

class Solution {
public:
    void getKthLevelNodes(TreeNode *root , int k , vector<int>&ans){
        if(!root){
            return;
        }

        if(k == 0){
            ans.push_back(root->val);
            return;
        }

        getKthLevelNodes(root->left , k - 1 , ans);
        getKthLevelNodes(root->right , k - 1 , ans);
    }

    int helperFun(TreeNode *root , int target , int k , vector<int>&ans){ 
        if(!root)
        {
            return -1;
        }

        if(root->val == target)
        {
            getKthLevelNodes(root , k , ans);
            return 0;
        }

        int dl = helperFun(root->left , target , k , ans);
        if(dl != -1){
            if(dl + 1 == k){
                ans.push_back(root->val);
            }
            else{
                getKthLevelNodes(root->right , k - 2 - dl , ans);
            }

            return dl + 1;
        }

        int dr = helperFun(root->right , target , k , ans);
        if(dr != -1){
            if(dr + 1 == k){
                ans.push_back(root->val);
            }
            else{
                getKthLevelNodes(root->left , k - 2 - dr , ans);
            }

            return dr + 1;
        }

        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        helperFun(root , target->val , k , ans);

        return ans;
    }
};
