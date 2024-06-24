//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void solve(vector<int>& nums, vector<int>& ans){
        if(nums.empty())
            return;
            
        int size = nums.size();
        
        int mid = (size/2) - 1;
        if(size&1)
            mid = size/2;
            
        ans.push_back(nums[mid]);
        
        vector<int>left(nums.begin(),nums.begin()+mid);
        vector<int>right(nums.begin()+mid+1,nums.end());
        
        solve(left,ans);
        solve(right,ans);
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int>ans;
        solve(nums,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends