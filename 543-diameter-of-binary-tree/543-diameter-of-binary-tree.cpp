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
        int temp = 1 + max(l,r);
        int ans = max(temp,1+l+r);//1+l+r reprsents diameter of tree which includes current node
        res = max(res,ans);
        
        return temp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        int res = INT_MIN;
        int temp = solve(root,res);
        
        return res-1;
        
    }
};