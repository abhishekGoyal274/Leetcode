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
    int ans{0};
    vector<int> solve(TreeNode* root){
        if(root == NULL) return {0,0};
        auto l = solve(root->left);
        auto r = solve(root->right);
        
        int sum = root->val + l[0] + r[0]; 
        int n = l[1]+r[1]+1;
        
        if(round(sum/n) == root->val) ans++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};