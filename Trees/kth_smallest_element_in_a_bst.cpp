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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int idx = 1;
        compute(root,result, idx, k);
        return result;
    }
private:
    void compute(TreeNode* root, int& result, int& idx, int k){
        if(!root)return;
        compute(root->left,result,idx,k);
        if(idx == k){
            result = root->val;
            idx++;
            return;
        }
        else idx++;
        compute(root->right,result,idx,k);
    }
};
