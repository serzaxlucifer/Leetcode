/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* anomaly1 = NULL;
    TreeNode* anomaly2 = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);

    void recoverTree(TreeNode* root) 
    {
        digger(root);
        anomaly1->val += anomaly2->val;
        anomaly2->val = (anomaly1->val - anomaly2->val);
        anomaly1->val -= anomaly2->val;
    }

    void digger(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        digger(root->left);
        if(root->val < prev->val)
        {
            anomaly2 = root;
            if(anomaly1 == NULL)
            {
                anomaly1 = prev;
            }
        }
        
        prev = root;
        digger(root->right);
    }
};
