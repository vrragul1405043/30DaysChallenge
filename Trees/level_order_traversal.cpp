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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>result;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int current_level_size = Q.size();
            vector<int>temp(current_level_size);
            for(int i=0;i<current_level_size;i++){
                TreeNode* current_node = Q.front();
                Q.pop();
                temp[i] = current_node->val;
                if(current_node->left)Q.push(current_node->left);
                if(current_node->right)Q.push(current_node->right);
            }//end for
            result.push_back(temp);
        }//end while
        return result;
    }
};
