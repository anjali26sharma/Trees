//https://leetcode.com/problems/balanced-binary-tree/

class Solution {
public:
    
    int length(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int rh = length(root->right);
        int lh = length(root->left);
        return 1+ max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int rh = length(root->right);
        int lh = length(root->left);
        if(abs(rh-lh)<=1)
        {
            bool small = isBalanced(root->right);
            bool small2 = isBalanced(root->left);
            return small && small2;
        }
        else return false;
        
        
    }
};
