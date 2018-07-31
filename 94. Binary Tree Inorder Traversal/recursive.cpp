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
    void _iterate (TreeNode *root){
      if (root == NULL)
        return;
      else if (root->left == NULL && root->right == NULL)
        cout << root->val;
      else if (root->left != NULL && root->right != NULL){
          _iterate(root->left);
          cout << root-> val;
          _iterate(root->right);
      }
      else if (root->left != NULL && root->right == NULL){
        _iterate(root->right);
        cout << root->val;
      }
      else if (root->left == NULL && root->right != NULL){
        cout << root->val;
        _iterate(root->right);
      }
    }
};
