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
    TreeNode* invertTree(TreeNode* root) {

        function<void(TreeNode*)> doinvert = [&](TreeNode* node){

            if (node == nullptr) return;
            TreeNode * templ = node->left;
            node->left = node->right; 
            node->right = templ;
            doinvert(node->left);
            doinvert(node->right);
        };

        doinvert(root);
        return root;
        
    }
};
