//https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root== NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;             // BFS,so queue
        q.push({root,0});
        int ans = INT_MIN;
        while(!q.empty())
        {   int mini = q.front().second;          //Number id of first element at this level
            int size = q.size();
            int first,last;
            for(int i =0; i<size; i++)
            {
                int curr = q.front().second - mini;      //Sub number id of first element of this level from this current element and storing it in curr.
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curr;                   
                if(i == size-1) last = curr;
                if(node->left) q.push({node->left,(long long)curr*2 +1});            //Type casting it long long to avoid integer overflow
                if(node->right) q.push({node->right,(long long)curr*2 +2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};
