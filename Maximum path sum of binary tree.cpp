//https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    
    int solve(TreeNode* root, int& maxi)
    {
        if(root == NULL)
            return 0;
        int ls = solve(root->left, maxi);
        int rs = solve(root->right, maxi);
        if(ls<0)
            ls = 0;
        if(rs<0)
            rs =0;
        maxi = max(maxi, root->val + ls+ rs);
        return root->val + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = solve(root,maxi);
        return maxi;
    }
};
