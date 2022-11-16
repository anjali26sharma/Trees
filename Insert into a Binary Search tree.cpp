//https://leetcode.com/problems/insert-into-a-binary-search-tree/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int input) {
       if(root == NULL)
        return new TreeNode(input);
       TreeNode * node = root;
       while(true)
       {
           if(node->val > input)
           {
               if(node->left) node = node->left;
               else
               { TreeNode* curr = new TreeNode(input);
                 node->left = curr;
                 break;
               }
           }
           else 
           {
               if(node->right) node = node->right;
               else
               { TreeNode* curr = new TreeNode(input);
                 node->right = curr;
                break;
               }
           }
          
       }
        return root;
    }   
};
