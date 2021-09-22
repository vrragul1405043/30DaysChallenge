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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>table;
        for(int i=0;i<inorder.size();i++) table[inorder[i]]=i;
        return constructTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,table);
    }
private:
    TreeNode* constructTree(vector<int>&inorder,int iStart, int iEnd, vector<int>&postorder, int pStart, int pEnd, unordered_map<int,int>&table){
        if(iStart>iEnd || pStart>pEnd)return NULL;
        TreeNode* root = new TreeNode(postorder[pEnd]);
        int iRoot = table[postorder[pEnd]];
        int numsLeft = iRoot-iStart;
        root->left = constructTree(inorder,iStart,iRoot-1,postorder,pStart,pStart+numsLeft-1,table);
        root->right = constructTree(inorder,iRoot+1,iEnd,postorder,pStart+numsLeft,pEnd-1,table);
        return root;
    }
};
