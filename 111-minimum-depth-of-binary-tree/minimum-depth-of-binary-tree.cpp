class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        // If left child is missing
        if(root->left == nullptr)
            return 1 + minDepth(root->right);

        // If right child is missing
        if(root->right == nullptr)
            return 1 + minDepth(root->left);

        // If both children exist
        return 1 + min(
            minDepth(root->left),
            minDepth(root->right)
        );
    }
};