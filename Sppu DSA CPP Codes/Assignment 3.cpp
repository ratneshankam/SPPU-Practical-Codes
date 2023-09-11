#include<iostream>
#include<iomanip>
using namespace std;
class node {
	int data;
	node *left;
	node *right;
public:
	node() {
		left = NULL;
		right = NULL;
		data = 0;
	}
	friend class bsTree;
	friend class stack;
};
class stack {
	node *arr[50];
	int top;
public:
	stack() {
		top = -1;
	}
	int isFull() {
		if (top == 50)
			return 1;
		else
			return 0;
	}
	int isEmpty() {
		if (top == -1)
			return 1;
		else
			return 0;
	}
	void push(node *add) {
		if (isFull())
			cout << "stack is full" << endl;
		else {
			top++;
			arr[top] = add;
		}
	}
	node* pop() {
		if (isEmpty()) {
			cout << "Nothing to pop" << endl;
			return NULL;
		} else {
			node *dat = arr[top];
			top--;
			return dat;
		}
	}
};
class bsTree {
public:
	node *root;
	bsTree() {
		root = NULL;
	}
	node* creatNode();
	void insertNode();
	void disMin();
	void disTree();
	void getMirror(node*);
	void bSearch(node* root, int key);
	void findHeight();
	int cntHeight(node* root, int key);
};
node* bsTree::creatNode() {
	node* temp;
	temp = new node;
	cout << "Enter data to be inserted:";
	cin >> temp->data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void bsTree::insertNode() {
	bsTree bs;
	node *temp;
	temp = bs.creatNode();
	if (root == NULL)
		root = temp;
	else {
		node *ptr;
		ptr = root;
		while (1) {
			if (ptr->data > temp->data) {
				if (ptr->left == NULL) {
					ptr->left = temp;
					break;
				} else
					ptr = ptr->left;
			} else if (ptr->data < temp->data) {
				if (ptr->right == NULL) {
					ptr->right = temp;
					break;
				} else
					ptr = ptr->right;
			}
		}
	}
}
void bsTree::disMin() {
	node *ptr;
	if (root == NULL)
		cout << "Tree is empty" << endl;
	else {

		ptr = root;
		while (ptr->left != NULL) {
			ptr = ptr->left;
		}
	}
	cout << "Minimum value is:" << ptr->data << endl;
}
void bsTree::disTree() {
	if (root == NULL)
		cout << "Tree is empty." << endl;
	else {
		node *ptr = root;
		stack s;
		while (1) {
			while (ptr != NULL) {
				s.push(ptr);
				cout << ptr->data << left << setw(12) << "\t" << ptr << "\t"
						<< left << setw(12) << ptr->left << "\t" << ptr->right
						<< endl;
				ptr = ptr->left;
			}
			if (!s.isEmpty()) {
				ptr = s.pop();
				ptr = ptr->right;
			} else
				break;
		}
	}
}
/*void bsTree::disTree(node* root) {
 if (root == NULL) {
 return;
 } else {
 bsTree bs;
 bs.disTree(root->left);
 cout << root->data << " ";
 bs.disTree(root->right);
 }
 }*/
void bsTree::getMirror(node* root) {
	if (root == NULL) {
		return;
	}
	bsTree bs;
	bs.getMirror(root->left);
	bs.getMirror(root->right);
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}
void bsTree::bSearch(node* root, int key) {
	bsTree bs;
	if (root == NULL) {
		cout << "Key not found." << endl;
		return;
	} else if (root->data == key) {
		cout << "Key found @ " << root << endl;
		return;
	} else if (key < root->data)
		bs.bSearch(root->left, key);
	else
		bs.bSearch(root->right, key);
}
void bsTree::findHeight() {
	int cnt = 0;
	bsTree bs;
	int cnt2;
	if (root == NULL)
		cout << "Tree is empty." << endl;
	else {
		node *ptr = root;
		stack s;
		while (1) {
			while (ptr != NULL) {
				s.push(ptr);
				if ((ptr->left == NULL) && (ptr->right == NULL)) {

					cnt2 = bs.cntHeight(this->root, ptr->data);
					if (cnt2 > cnt)
						cnt = cnt2;
				}
				ptr = ptr->left;
			}
			if (!s.isEmpty()) {
				ptr = s.pop();
				ptr = ptr->right;
			} else
				break;
		}
	}
	cout << "\nHeight of tree is: " << cnt << endl;
	cout<<"\nThere are "<<(cnt+1)<<" nodes in longest path."<<endl;
}
int bsTree::cntHeight(node* root, int key) {
	int cnt = 0;
	node* ptr;
	ptr = root;        //can not use 'this->root' as calling object is different
					   //(local obj from calling function)
	while (1) {
		if (ptr->data == key) {
			return cnt;
		} else if ((ptr->data) > key) {
			ptr = ptr->left;
			cnt++;
		} else if ((ptr->data) < key) {
			ptr = ptr->right;
			cnt++;
		}
	}
}
int main() {
	bsTree bs;
	int slct;
	char ch;
	do {
		cout << "#menu:" << "\n\t1.Create Binary Search Tree" << "\n\t2.Insert"
				<< "\n\t3.Display" << "\n\t4.Find Minimum"
				<< "\n\t5.Get Mirror tree" << "\n\t6.Search Key"
				<< "\n\t7.Find Height of tree" << "\n\t8.Exit" << endl;
		cout << "Select--> ";
		cin >> slct;
		switch (slct) {
		case 1:
			ch = 'y';
			while (ch == 'y' || ch == 'Y') {
				bs.insertNode();
				cout << "#continue insertion (y/n) ?";
				cin >> ch;

			}
			cout << "Binary Search tree created successfully." << endl;
			break;
		case 2:
			bs.insertNode();
			break;
		case 3:
			cout << "Preorder traversal of tree is as follow:" << endl;
			bs.disTree();
			break;
		case 4:
			bs.disMin();
			break;
		case 5:
			bs.getMirror(bs.root);
			break;
		case 6:
			int key;
			cout << "Enter key to be searched: ";
			cin >> key;
			bs.bSearch(bs.root, key);
			break;
		case 7:
			bs.findHeight();
		case 8:
			return 0;
		default:
			cout << "Invalid Choice." << endl;
		}
		cout << "\n#menu/exit (y/n) ?";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return 0;
}

