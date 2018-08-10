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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> final_;
      traverseLevel(root, final_);
      return final_;
    }
        /* Function to print level order traversal a tree*/
    void traverseLevel(TreeNode* root, vector<vector<int>>& final_)
    {
        int h = height(root);
        int i;
        for (i=1; i<=h; i++){
            vector<int> level_;
            nodeInGivenLevel(root, i, level_);
            final_.push_back(level_);
          }
    }
    /* Print nodes at a given level */
    void nodeInGivenLevel(TreeNode* root, int level, vector<int>& level_)
    {
        if (root == NULL)
            return;
        if (level == 1)
            level_.push_back(root->val);
        else if (level > 1)
        {
            nodeInGivenLevel(root->left, level-1, level_);
            nodeInGivenLevel(root->right, level-1, level_);
        }
    }
    int height(TreeNode* node){
      if (node == NULL)
        return 0;
      else{
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
          return (1 + lheight);
        else
          return (1 + rheight);
      }
    }
};
