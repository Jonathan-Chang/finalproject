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
  

class RBTree 
{ 


    
public: 
	void rotateLeft(Node *&, Node *&); 
    void rotateRight(Node *&, Node *&); 
    void fix(Node *&, Node *&); 
	 Node *root; 
    RBTree() { root = NULL; } 
    void insert(const int &n); 
    void inorder(); 
    void levelOrder(Node *root); 
}; 
  

void inorder(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    inorderHelper(root->left); 
    cout << root->data << "  "; 
    inorderHelper(root->right); 
} 
  


Node* createNewNode(int data){
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->color = "RED";

	return newNode;



}




Node* BSTInsert(Node* root, Node *node) 
{ 

    if (root == NULL) 
       return node; 
  
  
    if (node->data < root->data) 
    { 
        root->left  = BSTInsert(root->left, node); 
        root->left->parent = root; 
    } 
    else if (node->data > root->data) 
    { 
        root->right = BSTInsert(root->right, node); 
        root->right->parent = root; 
    } 
  
   
    return root; 
} 
  

void RBTree::rotateLeft(Node *&root, Node *&node) 
{ 
    Node *temp = node->right; 
  
    node->right = temp->left; 
  
    if (node->right != NULL) 
        node->right->parent = node; 
  
    temp->parent = node->parent; 
  
    if (node->parent == NULL) 
        root = temp; 
  
    else if (node == node->parent->left) 
        node->parent->left = temp; 
  
    else
        node->parent->right = temp; 
  
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
	cout << "hi" << endl;
        node->parent->right = temp; 
   }
	  
    temp->right = node; 
    node->parent = temp; 
} 
  

void RBTree::fix(Node *&root, Node *&node) 
{ 
	
  
	while ((node != root) && (node->color != "BLACK") && (node->parent->color == "RED")){ 
  		
	
  
      
		if (node->parent == node->parent->parent->left){ 
  
			
			node->uncle = node->parent->parent->right; 
  
        		if(node->uncle != NULL && node->uncle->color == "RED"){
			
				node->parent->parent->color = "RED";
				node->parent->color = "BLACK";
				node->uncle->color = "BLACK";
				node = node->parent->parent;
				
			} 
  
			else{ 
           			
				if (node == node->parent->right){ 
					
					rotateLeft(root, node->parent); 
					node = node->parent;
					node->parent = node->parent;
					
				} 
  				
				if(node == node->parent->left){
                			
					rotateRight(root, node->parent->parent);
					
					string tempColor = node->parent->color;
					node->parent->color = node->parent->parent->color;
					node->parent->parent->color = tempColor;
					node = node->parent; 
					
				}
			} 
       		} 
  
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
					Node* tempNode = node->parent;
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
  
void levelOrder(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    std::queue<Node *> q; 
    q.push(root); 
  
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        cout << temp->data << "  "; 
        q.pop(); 
  
        if (temp->left != NULL) 
            q.push(temp->left); 
  
        if (temp->right != NULL) 
            q.push(temp->right); 
	
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
    tree.insert(7); 
    tree.insert(6); 
    tree.insert(5); 
    tree.insert(4); 
    tree.insert(3); 
    tree.insert(2); 
    tree.insert(1); 
	
    levelOrder(tree.root);
    
   
    return 0; 
} 


int main(int argc, char* argv[]){



         

	
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
		//valueVector.push_back(value);
	}
	
	inputFile.close();
	

}


*/


























