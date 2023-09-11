#include<iostream>
#include<string.h>
#include <iomanip>
#include"str.h"
using namespace std;
class node {
	string keyw;
	string mean;
	node* left;
	node* right;
public:
	node() {
		keyw = "XYZ";
		mean = "PQR";
		left = NULL;
		right = NULL;
	}
	friend class dict;
};
class dict {
public:
	node *root;
	dict() {
		root = NULL;
	}
	node* creatNode();
	void insertNode();
	void disDict(node* root);
	void disMean(node* root, string key);
	void updtMean(node* root, string key);
	void deltWord(string key);
};
node* dict::creatNode() {
	node* temp;
	temp = new node;
	cout << "Enter word: ";
	cin >> temp->keyw;
	cout << "Enter meaning: ";
	cin >> temp->mean;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void dict::insertNode() {
	dict dc;
	node *temp;
	temp = dc.creatNode();
	if (root == NULL)
		root = temp;
	else {
		node *ptr;
		ptr = root;
		while (1) {
			str s;
			if (s.stcmp(ptr->keyw, temp->keyw))
				if (ptr->left == NULL) {
					ptr->left = temp;
					break;
				} else
					ptr = ptr->left;
			else if (ptr->right == NULL) {
				ptr->right = temp;
				break;
			} else
				ptr = ptr->right;
		}
	}
}
void dict::disDict(node* root) {
	if (root == NULL) {
		return;
	} else {
		dict dc;
		dc.disDict(root->left);
		cout << left << setw(20) << root->keyw << "\t: " << root->mean << endl;
		dc.disDict(root->right);
	}
}
void dict::disMean(node* root, string key) {
	dict dc;
	str s;
	static int count = 0;
	if (root == NULL) {
		cout << "Key not found." << endl;
		return;
	} else if (root->keyw == key) {
		cout << left << setw(20) << root->keyw << "\t:" << root->mean << endl;
		cout << "Found after " << ++count << " comaparisons." << endl;
		count = 0;
		return;
	} else if (s.stcmp(root->keyw, key)) {
		count++;
		dc.disMean(root->left, key);
	} else {
		count++;
		dc.disMean(root->right, key);
	}
}
void dict::updtMean(node* root, string key) {
	dict dc;
	str s;
	string meant;
	if (root == NULL) {
		cout << "Key not found." << "\nCan not change meaning." << endl;
		return;
	} else if (root->keyw == key) {
		cout << left << setw(20) << root->keyw << "\t:" << root->mean << endl;
		cout << "Enter new meaning: ";
		cin >> meant;
		root->mean = meant;
		cout << "\nChanged meaning successfully." << endl;
		return;
	} else if (s.stcmp(root->keyw, key)) {

		dc.updtMean(root->left, key);
	} else {

		dc.updtMean(root->right, key);
	}
}
void dict::deltWord(string key) {
	node* ptr = root;
	static node* temp = ptr;
	str s;
	while (ptr != NULL) {
		if (ptr->keyw == key) {
			break;
		}
		if (s.stcmp(ptr->keyw, key)) {
			temp = ptr;
			ptr = ptr->left;
		} else {
			temp = ptr;
			ptr = ptr->right;
		}
	}
	if (ptr == NULL) {
		cout << "Word not found to delete." << endl;
		return;
	} else {
		if (ptr->left == NULL && ptr->right == NULL) {
			if (temp->left == ptr)
				temp->left = NULL;
			else
				temp->right = NULL;
			delete ptr;
		} else if (ptr->left == NULL || ptr->right == NULL) {
			if (temp->left == ptr) {
				if (ptr->left == NULL) {
					temp->left = ptr->right;
				} else
					temp->left = ptr->left;
			} else {
				if (ptr->left == NULL) {
					temp->right = ptr->right;
				} else
					temp->right = ptr->left;
			}
			delete ptr;
		} else {
			node* min;
			min = ptr->right;
			while (min->left != NULL) {
				min = min->left;
			}
			ptr->keyw = min->keyw;
			ptr->mean = min->mean;
			if (ptr->right == min)
				ptr->right = NULL;
			delete min;
		}
		cout << "Word deleted successfully" << endl;
		return;
	}
}
int main() {
	dict dc;
	int slct;
	char ch;
	do {
		cout << "#menu:" << "\n\t1.Creat dictionary" << "\n\t2.Insert new word"
				<< "\n\t3.Display" << "\n\t4.Search meaning"
				<< "\n\t5.Update meaning" << "\n\t6.Delete word" << "\n\t7.Exit"
				<< endl;
		cout << "Select--> ";
		cin >> slct;
		switch (slct) {
		case 1:
			ch = 'y';
			while (ch == 'y' || ch == 'Y') {
				dc.insertNode();
				cout << "#continue insertion (y/n) ?";
				cin >> ch;

			}
			cout << "Binary Search tree created successfully." << endl;
			break;
		case 2:
			dc.insertNode();
			break;
		case 3:
			cout << "Dictionary displayed in decending sequence:" << endl;
			dc.disDict(dc.root);
			break;
		case 4: {
			string key;
			cout << "Search: ";
			cin >> key;
			dc.disMean(dc.root, key);
			break;
		}
		case 5: {
			string key;
			cout << "What to change: ";
			cin >> key;
			dc.updtMean(dc.root, key);
		}
			break;
		case 6: {
			string key;
			cout << "What to delete: ";
			cin >> key;
			dc.deltWord(key);
		}
			break;
		case 7:
			return 0;
		default:
			cout << "Invalid Choice." << endl;
		}
		cout << "\n#menu/exit (y/n) ?";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return 0;
}

