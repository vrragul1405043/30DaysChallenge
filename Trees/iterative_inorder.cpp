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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        TreeNode* node = root;
        vector<int>result;
        stack<TreeNode*>S;
        while(true){
            if(node){
                S.push(node);
                node = node->left;
            }
            else{
                if(S.empty())break;
                node = S.top();
                S.pop();
                result.push_back(node->val);
                node = node->right;
            } 
        }//end while
        return result;
    }
};
