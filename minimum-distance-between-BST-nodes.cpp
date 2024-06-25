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

    void solve(TreeNode* root , int& res, int &pre){
        if(!root)
            return;

        solve(root->left,res,pre);
        if(pre != -1)
            res = min(res,root->val - pre);
        pre = root->val;

        solve(root->right,res,pre);
    }
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        int pre = -1;

        solve(root,res,pre);

        return res;
    }
};