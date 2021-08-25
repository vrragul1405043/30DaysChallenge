/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>res;
        if(!root)return res;
        if(!isLeafNode(root))res.push_back(root->val);
        addLeftBoundary(root, res);
        addLeafNodes(root, res);
        addRightBoundary(root, res);
        return res;
    }
 private:
    bool isLeafNode(TreeNode* temp){
        return (temp!=NULL) && (temp->left==NULL) && (temp->right==NULL);
    }
    
    void addLeftBoundary(TreeNode* current, vector<int>&res){
        current = current->left;
        while(current){
            if(!isLeafNode(current))res.push_back(current->val);
            if(current->left)current = current->left;
            else current = current->right;
        }
    }
    
    void addRightBoundary(TreeNode* current, vector<int>&res){
        current = current->right;
        stack<int>s;
        while(current){
            if(!isLeafNode(current))s.push(current->val);
            if(current->right)current = current->right;
            else current = current->left;
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
    }
    
    void addLeafNodes(TreeNode* current, vector<int>&res){
        if(isLeafNode(current)){
            res.push_back(current->val);
            return;
        }
        if(current->left)addLeafNodes(current->left,res);
        if(current->right)addLeafNodes(current->right,res);
    }
    
};
