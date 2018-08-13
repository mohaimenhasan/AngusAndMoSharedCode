/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// do a breath-first search
// print like that
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> output;
      traverseLevel(root, output);
      return output;
    }

    void traverseLevel(TreeNode* root, vector<vector<int>>& final_)
    {
        int h = height(root);
        int i;
        for (i=1; i<=h; i++){
            vector<int> level_;
            nodesInGivenLevel(root, i, level_);
            if (i%2==0){
              reOrder(level_);
            }
            final_.push_back(level_);
          }
    }
    void reOrder(vector<int>& level_){
      reverse(level_.begin(), level_.end());
    }

    void nodesInGivenLevel(TreeNode* root, int level, vector<int>& myVector){
      if (root==NULL)
        return;
      if (level == 1)
        myVector.push_back(root->val);
      else{
        nodesInGivenLevel(root->left, level-1, myVector);
        nodesInGivenLevel(root->right, level-1, myVector);
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
