//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    bool solve(TreeNode* root, TreeNode* B, vector<TreeNode*> & ans)   // path from root to node
{  
    if(root == NULL)
    return false;
    ans.push_back(root);
    if(root->val == B->val)
    return true;
    bool S1, S2 = false;
    S1 = solve(root->left, B, ans);
    if(!S1)
    S2  = solve(root->right, B, ans);
    if(S1 || S2)
    return true;
    else
    {
        ans.pop_back();
        return false;
    }
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node;
        vector<TreeNode*> ans1;
        vector<TreeNode*> ans2;
        solve(root,p,ans1);                       // finding path from root to node p
        solve(root,q,ans2);
        int n = ans1.size(), m = ans2.size();     // finding path from root to node q
        int temp = n,i;
        if(n>m)
          temp = m;
        for(i = 1; i< temp ; i++)                 // loop starting from 1 bcz , root will always be common in both vectors ans1 n ans2
        {
            if(ans1[i] != ans2[i])                // comparing the last common element in ans1 n ans2 vector
            { node = ans1[i-1];                   // storing coomon value in node
              break;
            }
        }
        if(i == temp)
            if(ans1[temp-1]== ans2[temp-1])        // if either ans1 or ans2 runs out of length, we check if their last element was common and return it
                node = ans1[temp-1];
        return node;
    }
};
