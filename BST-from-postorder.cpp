//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/
Node* solve(Node* root, int data){
    if(!root)
        return new Node(data);
        
    if(data > root->data)
        root->right = solve(root->right,data);
    else
        root->left = solve(root->left,data);
        
    return root;
}

Node *constructTree (int post[], int size)
{
    Node* root = NULL;
    
    for(int i = size-1; i >= 0; i--){
        root = solve(root,post[i]);
    }
    return root;
}