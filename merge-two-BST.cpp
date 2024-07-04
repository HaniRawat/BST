//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    void inorder(Node* root, vector<int>& ans){
        if(!root)
            return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int>ans;
       
       inorder(root1,ans);
       inorder(root2,ans);
       
       
       sort(ans.begin(), ans.end());
       
       return ans;
    }
    
    
    //using morris traversal to create LL and then sorting them without extra space
    Node* getpred(Node* &root)
    {
        Node* temp = root->left;
        while (temp->right && temp->right != root)
            temp = temp->right;
        return temp;
    }
    
    Node* getroot(Node* &root)
    {
        Node* head = NULL;
        Node* temp2 = head;
        Node* temp = root;
        while (temp)
        {
            if (temp->left == NULL)
            {
                if (head == NULL)
                {
                    head = temp;
                    temp2 = head;
                }
                
                else    
                {
                    temp2->right = temp;
                    temp2 = temp;
                }
                temp = temp->right;
            }
            else
            {
                Node* pred = getpred(temp);
                if (pred->right == temp)
                    temp->left = NULL;
                else
                {
                    pred->right = temp;
                    temp = temp->left;
                }
            }
        }
        return head;
    }
    
    vector<int> merge(Node*root1, Node* root2){
        Node* head1 = root1;
        Node* head2 = root2;
        
        Node* head = NULL;
        
        if(head1 && head2){
            if(head1->data <= head2->data){
                head = head1;
                head1 = head1->right;
            }
            else{
                head = head2;
                head2 = head2->right;
            }
        }
        
        else if (head1){
            head = head1;
            head1 = head1->right;
        }
        else if(head2){
            head = head2;
            head2 = head2->right;
        }
        
        Node* temp = head;
        while(head1 && head2){
            if(head1->data <= head2->data){
                temp->right = head1;
                head1 = head1->right;
            }
            else{
               temp->right = head2;
               head2 = head2->right;
            }
           temp = temp->right;
       }
       if (head1)
            temp->right = head1;
            
       if (head2)
            temp->right = head2;
        }
        
        vector<int> ans;
       temp = head;
       while(temp)
       {
            ans.push_back(temp->data);
            temp = temp->right;
       }
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends