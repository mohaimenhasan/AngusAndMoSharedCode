/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        vector<TreeNode*> left_it;
        vector<TreeNode*> right_it;

        if (root == NULL)
            return output;
        if (root->left == NULL && root->right == NULL){
            output.push_back(root->val);
            return output;
        }

    }
};
