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
    vector<int> output;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return output;
        else if (root->left == NULL && root->right == NULL)
            output.push_back(root->val);
        else if (root->left != NULL && root->right != NULL){
          inorderTraversal(root->left);
          output.push_back(root->val);
          inorderTraversal(root->right);
         }
        else if (root->left != NULL && root->right == NULL){
            inorderTraversal(root->left);
            output.push_back(root->val);
        }
        else if (root->left == NULL && root->right != NULL){
            output.push_back(root->val);
            inorderTraversal(root->right);
        }
        return output;
    }
};

////---------- *** IGNORE THE FOLLOWING *** ----------------\\\\\ 

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
        vector<TreeNode*> all_;
        TreeNode* it_ = root;
        if (root == NULL)
            return output;

        // base
        if (root->left == NULL && root->right == NULL){
            output.push_back(root->val);
            return output;
        }

        //left

        while(it_->left!=NULL){
          left_it.push_back(it_);
          it_ = it_->left;
        }

        output.push_back(it_->val);
        for (int i =left_it.size()-1; i >= 0 ; i++){
          TreeNode* current_node = left_it[i];
          if (current_node->left !=NULL)
            output.push_back(current_node->left->val);
          output.push_back(current_node->val);
          if (current_node->right !=NULL)
            output.push_back(current_node->right->val);
        }

        //right
        it_ = root;
        while(it_->right!=NULL){
          right_it.push_back(it_);
          it_ = it_->right;
        }

        for (int i =0; i < right_it.size() ; i++){
          TreeNode* current_node = right_it[i];
          if (current_node->left !=NULL)
            output.push_back(current_node->left->val);
          output.push_back(current_node->val);
          if (current_node->right !=NULL)
            output.push_back(current_node->right->val);
        }

        output.push_back(it_->val);

        return output;

    }
};
