#include <iostream>

using namespace std;

class node {
public:
	double data;
	node* right = NULL;
	node* left = NULL;
};

class bst {
private:
	node* root;
public:
	bst() {
		root = NULL;
	}

	void insert(double data) {
		if (root == NULL) {
			node* temp = new node;
			temp->data = data;
			temp->right = NULL;
			temp->left = NULL;
			root = temp;
		}
		else {
			node* p = root;
			node* insert_location = root;
			while (p != NULL) {
				insert_location = p;
				if (data < p->data) {
					p = p->left;
				}
				else if (data > p->data) {
					p = p->right;
				}
				else {
					return;
				}
			}
			node* temp = new node;
			temp->data = data;
			temp->right = NULL;
			temp->left = NULL;
			if (data < insert_location->data) {
				insert_location->left = temp;
			}
			else if (data > insert_location->data) {
				insert_location->right = temp;
			}
		}
	}

	int height_of_node(node* p) {
		if (p == NULL) {
			return 0;
		}
		int x = height_of_node(p->left);
		int y = height_of_node(p->right);

		if (x > y) {
			return x + 1;
		}
		else if(y >= x) {
			return y + 1;
		}
	}

	bool is_balanced_rec(node* p) {
		if (p == NULL) {
			return 1;
		}
		int x = height_of_node(p->right);
		int y = height_of_node(p->left);

		if (!(x == y || x - y == 1 || y - x == 1)) {
			return 0;
		}
		else {
			return is_balanced_rec(p->left) && is_balanced_rec(p->right);
		}
	}

	bool is_balanced() {
		return is_balanced_rec(root);
	}
};



int main() {

	int n;
	cin >> n;

	double* arr = new double[n];
	bst b;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		b.insert(arr[i]);
	}

	if (b.is_balanced() == 1) {
		cout << "YES";
	}
	else if(b.is_balanced() == 0) {
		cout << "NO";
	}

	delete[]arr;
	return 0;
}