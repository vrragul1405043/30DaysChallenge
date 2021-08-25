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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root)return {};
        
        queue<TreeNode*>q;
        vector<vector<int>>result;
        bool isLeftToRight = true;
        q.push(root);
        while(!q.empty()){
            int SIZE = q.size();
            vector<int>row(SIZE);
            for(int i=0;i<SIZE;i++){
                TreeNode* temp = q.front();
                q.pop();
                int index = (isLeftToRight)?i:SIZE-i-1;
                row[index] = temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            isLeftToRight = !isLeftToRight;
            result.push_back(row);
        }//end while
        return result; 
    }
};
