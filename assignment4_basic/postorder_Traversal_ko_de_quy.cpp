/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
postOrder
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void postOrder(Node *root) {
//###INSERT CODE HERE -
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        Node* curr = stack1.top();
        stack1.pop();

        stack2.push(curr);

        if (curr->left) {
            stack1.push(curr->left);
        }

        if (curr->right) {
            stack1.push(curr->right);
        }
    }

    while (!stack2.empty()) {
        Node* curr = stack2.top();
        stack2.pop();

        std::cout << curr->data << " ";
    }
}
}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.postOrder(root);

    return 0;
}