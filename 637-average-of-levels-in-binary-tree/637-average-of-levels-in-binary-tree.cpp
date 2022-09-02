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
    vector<double> averageOfLevels(TreeNode* root) {
        double helper=0;
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        int n=0;
        auto *temp=root;
        while(!q.empty()){
            n=q.size();
            int k=n;
            helper=0;
            while(k--){
                temp=q.front();
                helper+=temp->val;
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                    }
            ans.push_back(double(helper/n));
            
        }
        return ans;
    }
};