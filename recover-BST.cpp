/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, vector<int>& ans, int& minValue){
    if(!A)
        return;
        
    solve(A->right,ans,minValue);
    minValue = min(minValue, A->val);
    
    if(A->val > minValue){
        ans[0] = minValue;
        ans[1] = A->val;
    }
    
    solve(A->left, ans,minValue);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans(2,0);
    int minValue = INT_MAX;
    solve(A,ans,minValue);
    return ans;
}