//https://leetcode.com/problems/binary-tree-preorder-traversal/

1.1 Recursion

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans,ans1,ans2;
        if(root == NULL)
            return ans;
        ans.push_back(root->val);
        ans1 = preorderTraversal(root->left);
        ans2 = preorderTraversal(root->right);
        ans.insert(ans.end(),ans1.begin(),ans1.end());
        ans.insert(ans.end(),ans2.begin(),ans2.end());
        return ans;
        
        
       
    }
};

1.2 
  class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> arr;
        preorder(arr, root);
        return arr;
    }
    
    void preorder(vector<int> &arr, TreeNode* root)
    {
        if(root == NULL)
            return;
        arr.push_back(root->val);
        preorder(arr, root->left);
        preorder(arr, root->right);
    }
};

2. Iterative Method

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
        if(root == NULL)
           return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode * Node1 = s.top();
            s.pop();
            ans.push_back(Node1->val);
            if(Node1->right != NULL)
                s.push(Node1->right);
            if(Node1->left != NULL)
                s.push(Node1->left);
        }
        
        return ans;
    }
};
