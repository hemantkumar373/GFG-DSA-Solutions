//{ Driver Code Starts
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
    Node* buildTreePostIn(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder,
                          int postStart, int postEnd, unordered_map<int, int> &inMap) {
        if(inStart > inEnd || postStart > postEnd) return NULL;
        
        Node* root = new Node(postorder[postEnd]);
        int inRoot = inMap[root->data];
        int numsLeft = inRoot - inStart;
        
        root->left = buildTreePostIn(inorder, inStart, inRoot-1, postorder, postStart,
                                     postStart+numsLeft-1, inMap);
        root->right = buildTreePostIn(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft,
                                      postEnd-1, inMap);
                               
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        unordered_map<int, int> inMap;
        
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends