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
    int solve(TreeNode* root,int &res){
        if(root == NULL) return 0;
        
        //hypothesis
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        //induction
        int temp = max(root->val+max(l,r),root->val); //we have taken only root->val because if both child's are negative then there is no use
        int ans = max(temp,root->val + l + r);
        res = max(res,ans);
        return temp;
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int temp = solve(root,res);
        return res;
    }
};