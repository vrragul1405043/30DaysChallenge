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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>table;
        for(int i=0;i<inorder.size();i++){
            table[inorder[i]]=i;
        }
        TreeNode* root = constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,table);
        return root;
    }
private:
    TreeNode* constructTree(vector<int>&preorder, int pStart, int pEnd, vector<int>&inorder, int iStart, int iEnd, unordered_map<int,int>&table){
        if(pStart>pEnd || iStart>iEnd)return NULL;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int iRoot = table[preorder[pStart]];
        int numsLeft = iRoot - iStart;
        root->left = constructTree(preorder, pStart+1, pStart+numsLeft,inorder,iStart, iRoot-1,table);
        root->right = constructTree(preorder, pStart+numsLeft+1, pEnd,inorder,iRoot+1,iEnd,table);
        return root;
    }
};
