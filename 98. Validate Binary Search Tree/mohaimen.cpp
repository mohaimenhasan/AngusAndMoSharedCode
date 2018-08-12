class Solution {
public:
    void traverseTree(vector<int>& lad, TreeNode* root){
      if (root->left)
        traverseTree(lad, root->left);
      lad.push_back(root->val);
      if (root->right)
        traverseTree(lad, root->right);
    }

    bool isValidBST(TreeNode* root) {
      if (!root)
        return true;
      vector<int> lad;
      traverseTree(lad, root);
      for (int i=0; i < lad.size()-1; i++){
        if (lad[i] >= lad[i+1])
          return false;
      }
      return true;
    }

};
