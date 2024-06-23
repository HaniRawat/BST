/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode* root, int &k, int &ans){
    if(!root)
        return;
        
    solve(root->left,k,ans);
    --k;
    
    if(k == 0){
        ans = root->val;
        return;
    }
    
    solve(root->right, k, ans);
}
int Solution::kthsmallest(TreeNode* root, int k) {
    int ans = 0;
    solve(root,k,ans);
    return ans;
}
