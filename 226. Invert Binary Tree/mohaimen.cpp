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
    TreeNode* invertTree(TreeNode* root) {

      if(root == NULL)
          return NULL;

      // base condition -> if both the children nodes are null then return out
      else if (root->left == NULL && root->right == NULL){
        return root;
        }

      else if (root->left != NULL && root->right != NULL){
          invertTree(root->left);
          invertTree(root->right);
          switchNode(root);
          return root;
      }

      // check left
      // if left is not null keep on going left and switch all the boys
      else if (root->left != NULL && root->right == NULL){
        invertTree(root->left);
        switchNode(root);
        return root;
      }

      // check right
      // if right is not null keep on going left and switch all the boys
      else if (root->right != NULL && root->left == NULL){
        invertTree(root->right);
        switchNode(root);
        return root;
      }

    }
    void switchNode(TreeNode* node){
      TreeNode* left_ = node->left;
      TreeNode* right_ = node->right;
      node->left = right_;
      node->right = left_;
    }
};
