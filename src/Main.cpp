#include "BST.hpp"

int main() {
  BST<int> tree;

  for (unsigned int i = 1000; i > 0; i--)
	  tree.insert(i);

  tree.print();
  
  return 0;
}
