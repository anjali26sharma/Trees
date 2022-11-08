//https://leetcode.com/problems/count-complete-tree-nodes/


/*
We go all the way to the left and count height, and all the way to the right and count height.
If they are equal, both subtrees are complete.
Otherwise, we will do the same for each subtree.
log(n)*log(n)
*/

class Solution {
public:
    int left(TreeNode* root)
    {   int ans =0;
        if(root == NULL)
            return 0;
        while(root)
            {
                ans++;
                root = root->left;
            }
        return ans;
    }
     int right(TreeNode* root)
    {   int ans =0;
        if(root == NULL)
            return 0;
        while(root)
            {
                ans++;
                root = root->right;
            }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh = left(root);
        int rh = right(root);
        if(lh == rh && lh !=0) return (pow(2,lh) -1);
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
    
};
