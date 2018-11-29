#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <typename T>
class Node {
public:
	Node() {
		data = nullptr;
		left = nullptr;
		right = nullptr;
	}
	
private:
	T *value;
	Node *left;
	Node *right;
};

template <typename T>
class BST {
public:
	BST() {
		root = nullptr;
	}

	void insert(T item) {
		
	}

	void remove(T item) {

	}

	Node *search(T item) {
		Node<T> *node = root;
		
		while (root) {
			if (item < root->value)
				node = node->left;
			else if (item > root->value)
				node = node->right;
			else
				return node;
		}

		return nullptr;
	}


private:
	Node<T> *root;
};


#endif
