//https://leetcode.com/problems/binary-tree-inorder-traversal/

1. Iterative Method

class Solution {
public:
    
    void solve(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true)
        {
            if(node!= NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty())
                break;
                TreeNode* Node1 = st.top();
                st.pop();
                ans.push_back(Node1->val);
                node = Node1->right;
            }
        }
        return ans;
    }
};

2. Recursive Method

class Solution {
public:
    
    void solve(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};
