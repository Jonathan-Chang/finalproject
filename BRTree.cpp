#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <unistd.h>
#include <map>
#include <math.h>
#include <set>
#include <ctime>
#include <queue>
#include <bits/stdc++.h> 
#include <deque>
#include <chrono>



using namespace std;
vector<int> valueVector;


struct Node 
{ 
	int data; 
	string color;
	Node *left;
	Node *right;
	Node *parent; 
	Node *grandparent;
	Node *uncle;
	
}; 
  

class RBTree { 


    
public: 
	void rotateLeft(Node *&, Node *&); 
	void rotateRight(Node *&, Node *&); 
	void fix(Node *&, Node *&); 
	Node *root; 
	RBTree() { root = NULL; } 
	void insert(const int &n); 
	void inorder(Node *root); 
	void levelOrder(Node *root); 
}; 
  

void inorder(Node *root){ 

	if (root == NULL){
		return; 
	}  
	inorder(root->left); 
	cout << root->data << "  "; 
	inorder(root->right); 
} 
  


Node* createNewNode(int data){
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->color = "RED";
	newNode->uncle = NULL;
	newNode->grandparent = NULL;

	return newNode;



}




Node* BSTInsert(Node* root, Node *node){ 

	if (root == NULL){
		return node; 
  	}
  
	if (node->data < root->data){ 
		root->left  = BSTInsert(root->left, node); 
		root->left->parent = root; 
    	} 
	else if (node->data > root->data){ 
        	root->right = BSTInsert(root->right, node); 
        	root->right->parent = root; 
    	} 
	else{
		root->right = BSTInsert(root->right, node); 
        	root->right->parent = root; 

	}
  
   
    	return root; 
} 
  

void RBTree::rotateLeft(Node *&root, Node *&node){ 
	Node *temp = node->right; 
  
	node->right = temp->left; 
  
	if (node->right != NULL){
		node->right->parent = node; 
  	}
	temp->parent = node->parent; 
  
	if (node->parent == NULL){
		root = temp; 
	}
  
	else if (node == node->parent->left){
		node->parent->left = temp; 
	}
  
	else{
        	node->parent->right = temp; 
	}
  
	temp->left = node; 
	node->parent = temp; 
} 
  
void RBTree::rotateRight(Node *&root, Node *&node) 
{ 
  
	Node *temp = node->left; 
   
	node->left = temp->right; 
  
	if (node->left != NULL){
	
		node->left->parent = node; 
   	}
  
    
	if (node->parent == NULL){
        	root = temp; 
	}
	else if (node == node->parent->left){
		node->parent->left = temp; 
    	}
	else{
		
		node->parent->right = temp; 
   	}
	  
	temp->right = node; 
	node->parent = temp; 
} 
  

void RBTree::fix(Node *&root, Node *&node) 
{ 

//http://www.stolerman.net/studies/cs521/red_black_trees.pdf //

	while ((node != root) && (node->color != "BLACK") && (node->parent->color == "RED")){ 
		 
		//Based on link above, if the node's parent is on the left subtree of the node's 			grandparent
		if (node->parent == node->parent->parent->left){ 

			node->uncle = node->parent->parent->right; 
  			//If the node's uncle is RED
			//Case 1 based on link above
			//We have to "Color a's father and uncle black and color the grandparent red
        		if(node->uncle != NULL && node->uncle->color == "RED"){
			
				node->parent->parent->color = "RED";
				node->parent->color = "BLACK";
				node->uncle->color = "BLACK";
				node = node->parent->parent;
				
			} 
  			//If the node's uncle is BLACK
			
			else{ 
           			//We have to rotate left around a's father if the node is on the 						parent's right 
				//subtree
				if (node == node->parent->right){ 
					
					rotateLeft(root, node->parent); 
					node = node->parent;
					node->parent = node->parent;
					
				} 
  				//We have to rotate right around a's father if the node is on the 						parent's left 
				//subtree
				//Then we have to switch the color between the node's father and 					  grandfather
				if(node == node->parent->left){
                			
					rotateRight(root, node->parent->parent);
					string tempColor = node->parent->color;
					node->parent->color = node->parent->parent->color;
					node->parent->parent->color = tempColor;
					node = node->parent; 
					
				}
			} 
       		} 
  
		//If the node's parent is on the right subtree


		else{ 
			node->uncle = node->parent->parent->right; 
        		if(node->uncle != NULL && node->uncle->color == "RED"){
				node->parent->parent->color = "RED";
				node->parent->color = "BLACK";
				node->uncle->color = "BLACK";
				node = node->parent->parent;
			} 
  
			else{ 
           			
				if (node == node->parent->left){ 
					rotateRight(root, node->parent); 
					
					node = node->parent;
					node->parent = node->parent;
					
				} 
  				
				if(node == node->parent->left){
           
					rotateLeft(root, node->parent->parent); 
					string tempColor = node->parent->color;
					node->parent->color = node->parent->parent->color;
					node->parent->parent->color = tempColor;
					node = node->parent; 
				}
			} 
		} 
    	} 
  
    root->color = "BLACK"; 
} 
  
void levelOrder(Node *root) { 
	if (root == NULL){
        	return; 
  	}
	queue<Node *> q; 
	q.push(root); 
  
	while (!q.empty()){
 
		Node *temp = q.front(); 
		cout << temp->data << "  "; 
		q.pop(); 
  
		if (temp->left != NULL){ 
            		q.push(temp->left); 
  		}
		if (temp->right != NULL){
            		q.push(temp->right); 
		}
	
	} 
}



void RBTree::insert(const int &data){ 
	Node *node = createNewNode(data); 
	root = BSTInsert(root, node); 
	fix(root, node); 
} 





int main() 
{ 
	RBTree tree;
	levelOrder(tree.root);
	return 0; 
} 

/*
int main(int argc, char* argv[]){



         

	RBTree tree;

	string inputFileName = argv[1];
	ifstream inputFile;
	inputFile.open(inputFileName);
	string line;	

	int value;

	while(getline(inputFile, line)){
		stringstream stringInput(line);
		string a;
		stringInput >> a;

		value = stoi(a);
		valueVector.push_back(value);
	}
	
	inputFile.close();

	for(int i = 0; i < valueVector.size(); i++){
		tree.insert(valueVector[i]);
	}
	

}


*/


























