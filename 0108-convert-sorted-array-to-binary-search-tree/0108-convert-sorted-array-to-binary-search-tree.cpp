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
    void MakeTree(vector<int> &nums, int l, int r, TreeNode* &root){
        if(l > r) return;
        int mid = (l+r)/2;
        root = new TreeNode();
        root->val = nums[mid];
        MakeTree(nums, mid+1,r, root->right);
        MakeTree(nums, l,mid-1, root->left);
    } 

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = nullptr;
        int l = 0; int r = nums.size() -1;
        MakeTree(nums, l,r, ans);
        return ans;
    }
};