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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        max_util(root, sum);
        return sum;
    }
private:
    int max_util(TreeNode* root, int& sum){
        if(!root)return 0;
        int lsum = max(0,max_util(root->left, sum));
        int rsum = max(0,max_util(root->right,sum));
        max_sum = max(max_sum,root->val + lsum + rsum);
        return max(lsum,rsum)+root->val;
    }
};
