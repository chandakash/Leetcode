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
        return buildTreeRec(preorder,inorder,0,inorder.size()-1,0);
    }
    
    TreeNode* buildTreeRec(vector<int>& preorder, vector<int>& inorder, int start, int end , int pIndex){
        
        if(start>end) return NULL;
        TreeNode *root = new TreeNode(preorder[pIndex]);
        int inIndex = start;
        while(preorder[pIndex]!=inorder[inIndex])inIndex++;
        
        root->left = buildTreeRec(preorder,inorder,start,inIndex-1,pIndex+1);
        root->right= buildTreeRec(preorder,inorder,inIndex+1,end,pIndex+ inIndex-start +1);
    return root;
    }
};