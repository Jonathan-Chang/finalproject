#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <typename T>
class Node {
public:
	Node();

private:
	T *data;
	Node *left;
	Node *right;
};

template <typename T>
class BST {
public:
	BST() {
		root = nullptr;
	}

private:
	Node<T> *root;
};


#endif
