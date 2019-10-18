#include<iostream> 
#include<map> 
using namespace std; 

#define INT_MAX 10
struct Node 
{
	int data; 
	int hd; 
	Node * left, * right; 
	Node(int key) 
	{ 
		data = key; 
		hd = INT_MAX; 
		left = right = NULL; 
	} 
}; 

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m) 
{
	if (root == NULL) 
		return; 
	if (m.find(hd) == m.end()) 
	{ 
		m[hd] = make_pair(root -> data, curr); 
	}
	else
	{ 
		pair < int, int > p = m[hd]; 
		if (p.second <= curr) 
		{ 
			m[hd].second = curr; 
			m[hd].first = root -> data; 
		} 
	}  
	printBottomViewUtil(root -> left, curr + 1, hd - 1, m); 
	printBottomViewUtil(root -> right, curr + 1, hd + 1, m); 
} 

void printBottomView(Node * root) 
{ 
	map < int, pair < int, int > > m; 
	printBottomViewUtil(root, 0, 0, m); 
	map < int, pair < int, int > > ::iterator it; 
	for (it = m.begin(); it != m.end(); ++it) 
	{ 
		pair < int, int > p = it -> second; 
		cout << p.first << " "; 
	} 
} 

int main() 
{ 
	Node * root = new Node(20); 
	root -> left = new Node(8); 
	root -> right = new Node(22); 
	root -> left -> left = new Node(5); 
	root -> left -> right = new Node(3); 
	root -> right -> left = new Node(4); 
	root -> right -> right = new Node(25); 
	root -> left -> right -> left = new Node(10); 
	root -> left -> right -> right = new Node(14); 
	cout << "Bottom view of the given binary tree :\n"; 
	printBottomView(root); 
	return 0; 
} 