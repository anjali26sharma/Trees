//https://www.interviewbit.com/problems/path-to-given-node/

bool solve1(TreeNode* root, int B, vector<int> & ans)
{  
    if(root == NULL)
    return false;
    ans.push_back(root->val);
    if(root->val == B)
    return true;
    bool S1, S2 = false;
    S1 = solve1(root->left, B, ans);
    if(!S1)
    S2  = solve1(root->right, B, ans);
    if(S1 || S2)
    return true;
    else
    {
        ans.pop_back();
        return false;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    solve1(A,B,ans);
    return ans;
}
