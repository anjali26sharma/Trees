//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
public:


    bool isLeaf(Node* root)
    {
        if(root->right == NULL && root->left == NULL)
        return true;
        else return false;
    }

    void leftBound(Node* root, vector<int> &ans)
    {
        Node* curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr))
            ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
            
        }
    }
    
    void leaves(Node* root, vector<int> &ans)
    {
        if(isLeaf(root))
        { ans.push_back(root->data);
          return ;
        }
        else
        {
            if(root->left) leaves(root->left,ans);
            if(root->right) leaves(root->right,ans);
        }
    }
    
    void rightBound(Node* root, vector<int> &ans)
    {
        vector<int> temp;
        Node* curr = root->right;
        while(curr){
          if(!isLeaf(curr))
          temp.push_back(curr->data);
          if(curr->right) curr = curr->right;
          else curr = curr->left;
        }
        for(int i = temp.size()-1; i>=0; i--)
        ans.push_back(temp[i]);
        
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL)
        return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        leftBound(root,ans);
        leaves(root,ans);
        rightBound(root,ans);
        return ans;
    }
};
