void recursion(TreeNode* root, int goal, vector<int>& path, bool& found)
{
    if(found || root == NULL)
    {
        return;
    }
    
    path.push_back(root->val);
    
    if(root->val == goal)
    {
        found = true;    // once found, prune all other searches.
        return;
    }
    
    recursion(root->left, goal, path, found);
    recursion(root->right, goal, path, found);
    if(!found)
    {
        path.pop_back();
    }
}

vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int> path;
    bool found = false;
    recursion(A, B, path, found);
    return path;
}
