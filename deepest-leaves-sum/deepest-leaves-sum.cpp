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

// USING DFS
class Solution {
public:
    int sum = 0;
    int maxDepth = 0;
    int deepestLeavesSum(TreeNode* root) {
       
        findSum(root,1);
        return sum;
    }
    
    void findSum(TreeNode* root, int curr)
    {
        if(root!=NULL)
        {
            if(curr>maxDepth)
            {
                sum = 0;
                maxDepth = curr;
            }
            if(curr == maxDepth)
            {
                sum += root->val;
            }
            
        findSum(root->left,curr+1);
        findSum(root->right,curr+1);
        }
    }
};


/*
// USING BFS.
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        // we will use bfs and level order traversal 
        int sum = 0;
        int last_sum = 0;
        if(root==NULL)
            return sum;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);// to mark we have checked that level.
        while(!q.empty())
        {
            TreeNode* x = q.front();
            q.pop();
            if(x==NULL)
            {
                if(q.size()==0)
                {
                    last_sum = sum;
                    break;
                }
                q.push(NULL);
                sum = 0;
            }
            else
            {
                sum+=x->val;
                if(x->left!=NULL)
                    q.push(x->left);
                if(x->right!=NULL)
                    q.push(x->right);
            }
        }
    return last_sum;
    }
};

*/