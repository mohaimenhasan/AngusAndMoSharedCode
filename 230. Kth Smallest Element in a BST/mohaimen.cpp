// solution should be as follows:
// do an in order traversal
// put the elements in a vector
// put find the kth element
// DONE YEET YEET 


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
    vector <int> allElements;
    int kthSmallest(TreeNode* root, int k) {
      traverseTree(root);
      return allElements[k-1];
    }
    void traverseTree(TreeNode* root){
      if (root == NULL)
        return;
      traverseTree(root->left);
      allElements.push_back(root->val);
      traverseTree(root->right);
    }
};
