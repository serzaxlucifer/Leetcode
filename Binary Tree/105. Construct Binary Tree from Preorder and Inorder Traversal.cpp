class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int, int> map;

        for(int i = 0; i < inorder.size(); i++)     // indexing
        {
            map[inorder[i]] = i;
        }

        return constructTree(preorder, inorder, map, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }

    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& map, int inStart, int inEnd, int preStart, int preEnd)
    {
        if(inStart > inEnd || preStart > preEnd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inElement = map[root->val];
        int eles = inElement - inStart;

        root->left = constructTree(preorder, inorder, map, inStart, inElement - 1, preStart + 1, preStart + eles);
        root->right = constructTree(preorder, inorder, map, inElement + 1, inEnd, preStart + eles + 1, preEnd);

        return root;
    }
};
