#include<bits/stdc++.h>
using namespace std;
map<long long,bool> appear;
vector<long long> ans;
class Node
{
public:
	long long value;
	Node* left;
	Node* right;
	long long deviation_from_root;
	Node(long long data, long long dev = 0)
	{
		value = data;
		left = NULL;
		right = NULL;
		deviation_from_root = dev;
	}
};
Node* insert(Node* root, long long data, long long dev)
{
	if (root == NULL) return new Node(data, dev);
	if (data <= root->value) 
	{
		dev--;
		root->left = insert(root->left, data,dev);
	}
	else 
	{
		dev++;
		root->right = insert(root->right, data,dev);
	}		
	return root;
}
void treeTravesal(Node* root)
{
	if (root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) 
	{
    	Node* node = q.front();
    	// cout<<node->value<<' '<<node->deviation_from_root<<endl;
    	if (appear[node->deviation_from_root] == 0) 
    	{
    		appear[node->deviation_from_root] = 1;
    		ans.push_back(node->value);
    	}
    	q.pop();
    	if (node->left != NULL) q.push(node->left);
	    if (node->right != NULL) q.push(node->right);
	}
}
int main()
{
	long long n;
	cin>>n;
	Node* node = NULL;
	for (long long i = 0; i < n; ++i)
	{
		long long data;
		cin>>data;
		node = insert(node,data,0);
	}
	treeTravesal(node);
	sort(ans.begin(), ans.end());
	for (auto x : ans)
	{
		cout<<x<<' ';
	}
	return 0;	
}