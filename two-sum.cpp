/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, int B, vector<int> &ans){
    if(!A)
        return;
        
    solve(A->left,B,ans);
    ans.push_back(A->val);
    solve(A->right,B,ans);
}
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int>ans;
    solve(A,B,ans);
    
    int i = 0;
    int j = ans.size()-1;
    
    bool exist = false;
    
    while(i < j){
        if(ans[i] + ans[j] > B)
            j--;
        else if(ans[i] + ans[j] < B)
            i++;
        else{
            exist = true;
            break;
        }
    }
    
    if(exist)
        return 1;
    return 0;
}