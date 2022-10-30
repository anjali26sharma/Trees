//https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    
    int height(TreeNode* root, int &dia)
    {
        if(root == NULL)
            return 0;
        int lh = height(root->left,dia);
        int rh = height(root->right,dia);
        dia = max(dia,lh+rh);
        return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia =0;
        int ans = height(root,dia);
        return dia;
    }
};
