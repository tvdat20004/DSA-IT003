/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
inOrder
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

	void inOrder(Node *root) {
//###INSERT CODE HERE -
	if (root == NULL) {
        return;
    }
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);
        if (current->left != NULL) {
            s1.push(current->left);
        }
        if (current->right != NULL) {
            s1.push(current->right);
        }
    }
    while (!s2.empty()) {
        Node* current = s2.top();
        s2.pop();
        cout << current->data << " ";
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
  
	myTree.inOrder(root);

	return 0;
}