//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ds;
        if(root== NULL)
            return ds;
        
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> ans;
            for(int i =0; i<size; i++)
            {
                TreeNode* Node1 = q.front();
                q.pop();
                ans.push_back(Node1->val);
                if(Node1->left!= NULL)
                    q.push(Node1->left);
                if(Node1->right != NULL)
                    q.push(Node1->right);
            }
            if(flag != 1)
            {
                reverse(ans.begin(), ans.end());
                
            }
            ds.push_back(ans);
            flag*=-1;
        }
        return ds;
    }
};
