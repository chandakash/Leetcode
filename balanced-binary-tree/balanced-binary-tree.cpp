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
    bool isBalanced(TreeNode* root) {
        return calcHeight(root)!=-1;
    }
    
    int calcHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int lHeight = calcHeight(root->left);
        int rHeight = calcHeight(root->right);
        
        if(lHeight==-1 || rHeight==-1 || abs(rHeight-lHeight)>1)
            return -1;
        
    return max(lHeight,rHeight)+1;
    }
    
};