//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int getLength(Node* head) {
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    
    // Function to rotate a linked list to the left by k positions.
    Node* rotate(Node* head, int k) {
        if (!head || k == 0) return head;
        
        int length = getLength(head);
        k = k % length;  // Adjust k to be within the bounds of the list
        if (k == 0) return head;  // No rotation needed
        
        // Step 1: Find the (k-1)th node
        int newLastNodePosition = k - 1;
        Node* newLastNode = head;
        
        for (int i = 0; i < newLastNodePosition; i++) {
            newLastNode = newLastNode->next;
        }
        
        // Step 2: Set the new head and break the list
        Node* newHead = newLastNode->next;
        newLastNode->next = nullptr;
        
        // Step 3: Find the end of the new list
        Node* end = newHead;
        while (end->next) {
            end = end->next;
        }
        
        // Step 4: Link the end of the new list to the original head
        end->next = head;
        
        return newHead;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends