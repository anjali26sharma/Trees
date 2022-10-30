//https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int rh = maxDepth(root->right);
        int lh = maxDepth(root->left);
        return 1+max(rh,lh);
    }
};
