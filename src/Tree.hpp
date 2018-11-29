#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <typename T>
class Node {
public:
  

private:
  T *data;
  Node<T> *left;
  Node<T> *right;
};

template <typename T>
class Tree {
public:
  bool insert(T);
  void remove(T);
  void search(T);

private:
  
};

#endif
