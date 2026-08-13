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
    int maxDepth(TreeNode* root) {
        int tree_depth = 0;

        if (root == nullptr) return 0;
        function<int(TreeNode*)> depth = [&](TreeNode* node){

            if(node->left == nullptr && node->right == nullptr) return 1; 

            else{
                int dl= 0, dr =0;
                if(node->left!=nullptr)  dl = 1 + depth(node->left);
                if(node->right!=nullptr) dr = 1 + depth(node->right);
                return max(dl,dr);
            }

        };

        tree_depth = depth(root);
        return tree_depth;

    }
};
