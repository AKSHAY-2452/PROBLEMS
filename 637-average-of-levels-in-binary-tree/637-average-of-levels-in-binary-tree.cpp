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
    
    int levelof(TreeNode* root){
        if(root == NULL) return 0;
        
        int a = levelof(root->left);
        int b = levelof(root->right);
        
        return 1+max(a,b);
        
    }
    
    void solve(TreeNode* root,int level,vector<vector<double>> &temp){
        if(root == NULL) return;
        temp[level].push_back(root->val);
        
        solve(root->right,level+1,temp);
        solve(root->left,level+1,temp);
        return;
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        int n = 0;
        n = levelof(root);
        
        vector<double> ans;
        vector<vector<double>> temp(n);
        int level = 0;
        solve(root,level,temp);
        
        for(int i = 0;i<temp.size();i++){
            double tempo = 0;
            for(int j = 0;j<temp[i].size();j++){
                tempo += temp[i][j]; 
            }
            ans.push_back(tempo/temp[i].size());
        }
        return ans;
    }
};