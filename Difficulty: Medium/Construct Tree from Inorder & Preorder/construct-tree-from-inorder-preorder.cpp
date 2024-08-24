//{ Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        createMapping(in, n);
        
        int preIndex = 0; // start index for preorder traversal
        return buildTreeHelper(in, pre, 0, n - 1, preIndex, n);
    }
    
private:
    unordered_map<int, int> valueToIndexMap;

    void createMapping(int in[], int size) {
        for (int i = 0; i < size; i++) {
            int element = in[i];
            int index = i;
            valueToIndexMap[element] = index;
        }
    }

    Node* buildTreeHelper(int in[], int pre[], int inorderStart, int inorderEnd, int& preIndex, int size) {
        if (preIndex >= size || inorderStart > inorderEnd) {
            return nullptr;
        }

        // first element in preorder is the root of the tree (or subtree)
        int element = pre[preIndex];
        preIndex++;
        
        Node* root = new Node(element);
        
        // find the index of the root in inorder
        int position = valueToIndexMap[element];
        
        // recursively build the left and right subtrees
        // build left subtree
        root->left = buildTreeHelper(in, pre, inorderStart, position - 1, preIndex, size);
        // build right subtree
        root->right = buildTreeHelper(in, pre, position + 1, inorderEnd, preIndex, size);
        
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends