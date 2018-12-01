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

	~Node() {
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

	~BST() {
		deleteTree(root);
	}

	void insert(T item) {
		if (!root) {
			root = new Node<T>(item);
			return;
		}

		Node<T> *node, *parent;
		node = root;

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
		removeRecur(root, item);
	}

	Node<T> *search(T item) {
		return searchRecur(item, root);
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

	Node<T> *searchRecur(T item, Node<T> *node) {
		if (!node)
			return nullptr;

		if (item == node->value)
			return node;
		else if (item < node->value)
			return searchRecur(item, node->left);
		else
			return searchRecur(item, node->right);

		return nullptr;
	}

	void removeRecur(Node<T> * &node, T item) {
		if (!node)
			return;
		
		if (item < node->value) {
			return removeRecur(node->left, item);
		}

		if (item > node->value) {
			return removeRecur(node->right, item);
		}
	    
		if (!node->left && !node->right) {
			delete node;
			node = nullptr;
		} else if (node->left && node->right) {
			Node<T> *predecessor = node->left;
			while (predecessor->right)
				predecessor = predecessor->right;
			
			node->value = predecessor->value;
			
			removeRecur(node->left, predecessor->value);
		} else {
			Node<T> *child = (node->left)? node->left: node->right;
			Node<T> *curr = node;
			
			node = child;
			
			delete curr;
		}
	}

	void deleteTree(Node<T> *node) {
		if (!node)
			return;

		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
};



#endif
