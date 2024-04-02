class Solution {
public:
    void traverse(TreeNode* root, vector<int>& __treeVal)
    {
        if(root == NULL)
        {
            return;
        }
        traverse(root->left, __treeVal);
        __treeVal.push_back(root->val);
        traverse(root->right, __treeVal);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) 
    {
        vector<int> treeVal;
        traverse(root, treeVal);
        vector<vector<int>> soln;

        for(int i = 0; i < queries.size(); i++)
        {
            int query = queries[i];

            auto index = lower_bound(treeVal.begin(), treeVal.end(), query);
            if(index != treeVal.end() && *index == query)
            {
                soln.push_back({query, query});
            }
            else
            {
                soln.push_back({index == treeVal.begin() ? -1 : *(index-1), index == treeVal.end() ? -1 : *index});
            }
        }

        return soln;
    }
};
