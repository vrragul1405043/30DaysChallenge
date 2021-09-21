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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return{};
        stack<TreeNode*>st1,st2;
        vector<int>result;
        st1.push(root);
        
        while(!st1.empty()){
            TreeNode* current_node = st1.top();
            st1.pop();
            st2.push(current_node);
            if(current_node->left)st1.push(current_node->left);
            if(current_node->right)st1.push(current_node->right);
        }
        
        while(!st2.empty()){
            result.push_back(st2.top()->val);
            st2.pop();
        }
        return result;
    }
};
