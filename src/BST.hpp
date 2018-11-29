#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <typename T>
class Node {
public:
	Node() {
		value = nullptr;
		left = nullptr;
		right = nullptr;
	}

	Node(T item) {
		value = item;
		left = nullptr;
		right = nullptr;
	}
	
	T value;
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
		Node<T> *node = root;
		Node<T> *parent;

		/* If root is null, add item to root */
		if (!root) {
			root = new Node<T>(item);
			return;
		}

		/* Find the correct position to place the item */
		while (node) {
			parent = node;

			if (item < node->value)
				node = node->left;
			else
				node = node->right;
		}

		if (item < parent->value)
			parent->left = new Node<T>(item);
		else
			parent->right = new Node<T>(item);
	}

	void remove(T item) {
		/*		Node *node, *parent;

		if (!root)
			return;

		*/
	}

	Node<T> *search(T item) {
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

	void print() {
		inorder(root);
	}

private:
	Node<T> *root;

	void inorder(Node<T> *node) {
		if (!node)
			return;
		
		inorder(node->left);
		std::cout << node->value << std::endl;
		inorder(node->right);
	}

};


#endif
