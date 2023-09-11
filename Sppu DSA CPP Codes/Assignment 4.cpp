#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	bool l;
	bool r;
	node() {
		data = 0;
		left = NULL;
		right = NULL;
		l = 0;
		r = 0;
	}
	friend class tbsTree;
};

class tbsTree {
public:
	node* head;
	tbsTree() {
		head = new node;
		head->r = 1;
		head->right = head;
	}
	static node* creatNode();
	bool insert();
	void disTree();
};
node* tbsTree::creatNode() {
	node* temp;
	temp = new node;
	cout << "Enter data to be inserted: ";
	cin >> temp->data;
	return temp;
}
bool tbsTree::insert() {
	node* temp;
	temp = tbsTree::creatNode();
	if (head->left == NULL) {
		head->left = temp;
		head->l = 1;
		temp->left = head;
		temp->right = head;
	} else {
		node* ptr;
		ptr = head->left;
		while (1) {
			if (ptr->data > temp->data) {
				if (ptr->l != 1) {
					temp->left = ptr->left;
					ptr->l = 1;
					ptr->left = temp;
					temp->right = ptr;
					break;
				} else {
					ptr = ptr->left;

				}
			} else if (ptr->data < temp->data) {
				if (ptr->r != 1) {
					temp->right = ptr->right;
					ptr->r = 1;
					ptr->right = temp;
					temp->left = ptr;
					break;
				} else
					ptr = ptr->right;
			} else {
				cout << "Entered data already exist; not inserted." << endl;
				return 0;
			}
		}
	}
	return 1;
}
void tbsTree::disTree() {
	node* ptr;
	ptr = head->left;
	//int n=11;
	cout << "\nInorder traversal of TBST is as follow:" << endl;
	while (ptr->l != 0) {
		ptr = ptr->left;
	}
	while (ptr->right != head) {
		if (ptr->r == (ptr->right->r)) {
			cout << ptr->data << "  ";
			ptr = ptr->right;
			while (ptr->l != 0) {
				ptr = ptr->left;
			}
		}
		cout << ptr->data << "  ";
		ptr = ptr->right;
	}
	cout << ptr->data << "  ";
}
int main() {
	tbsTree tbs;
	int n;
	int flag = 1;
	cout << "Enter how many node you want to enter: ";
	cin >> n;
	for (int i = 0; i < n;) {
		flag = tbs.insert();
		if (flag)
			i++;
	}
	cout << "\nTBST created successfully." << endl;
	tbs.disTree();
	cout << "\nEnd." << endl;
	return 0;
}

