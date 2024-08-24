//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        createMapping(in, n);
        
        // last index of postorder array
        int postIndex = n - 1;
        
        return buildTreeHelper(in, post, 0, n - 1, postIndex, n);
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

    Node* buildTreeHelper(int in[], int post[], int inorderStart, int inorderEnd, int& postIndex, int size) {
        if (postIndex < 0 || inorderStart > inorderEnd) {
            return nullptr;
        }

        // last element in postorder is the root of the current subtree
        int element = post[postIndex];
        postIndex--;
        
        Node* root = new Node(element);
        
        int position = valueToIndexMap[element];
        
        // recursively build the right and left subtrees
        // build right subtree first because postorder traversal is processed from end to start
        root->right = buildTreeHelper(in, post, position + 1, inorderEnd, postIndex, size);
        root->left = buildTreeHelper(in, post, inorderStart, position - 1, postIndex, size);
        
        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends