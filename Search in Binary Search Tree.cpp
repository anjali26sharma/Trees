//https://leetcode.com/problems/search-in-a-binary-search-tree/

//1. Loop Runtime - 47ms
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        while(root && root->val != val)
        {
           root = root->val > val? root->left : root->right;
        }
        return root;
    }
};


//2. Recurrsion Runtime - 108ms
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        if(root->val == val) return root;
        else if(root->val < val)
            return searchBST(root->right , val);
        else return searchBST(root->left,val);
    }
};
