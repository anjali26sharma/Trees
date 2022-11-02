//https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool solve(TreeNode* l, TreeNode* r)
    {
        if(l==NULL || r==NULL)
            return l==r;
        return (l->val == r->val) && (solve(l->left,r->right)) && solve(l->right,r->left);   
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode * l = NULL;
        TreeNode * r = NULL;
        if(root->left) l = root->left;
        if(root->right)  r = root->right;
        return solve(l,r);
    }
};
