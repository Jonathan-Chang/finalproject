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
vector<int> dataVector;


struct Node 
{ 
	int data; 
	string color;
	Node *left;
	Node *right;
	Node *parent; 
	Node *grandparent;
	Node *uncle;
	Node *sibling;
	
	void moveDown(Node *node){
	if(node != NULL){
		if(node == node->parent->left){
			node->parent->left = node;
		

		}
		else{
			node->parent->right = node;

		}

	}
	node->parent = node->parent;
	node->parent = node;



	}	
	
}; 
  

class RBTree { 


    
public: 
	void rotate(Node *&, Node *&, string);
	void fixInsert(Node *&, Node *&); 
	void fixDelete(Node *);
	void deleteVal(const int &data);
	Node *root; 
	RBTree() { root = NULL; } 
	void insert(const int &n); 
	void inorder(Node *root); 
	void levelOrder(Node *root); 
	void deleteNode(Node *node);
	Node *search(int n);
	void deleteRotate(Node *x, string direction);



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




Node* BinaryInsert(Node* root, Node *node){ 

	if (root == NULL){
		return node; 
  	}
  
	if (node->data < root->data){ 
		root->left  = BinaryInsert(root->left, node); 
		root->left->parent = root; 
    	} 
	else if (node->data > root->data){ 
        	root->right = BinaryInsert(root->right, node); 
        	root->right->parent = root; 
    	} 
	else{
		root->right = BinaryInsert(root->right, node); 
        	root->right->parent = root; 

	}
  
   
    	return root; 
} 
 
void RBTree::deleteRotate(Node *x, string direction){
	if(direction == "RIGHT"){
		Node *parent = x->left;
		if(x == root){
			root = parent;
		}

		x->moveDown(parent);
		x->left = parent->right;

		if(parent->right != NULL){
			parent->right->parent = x;
			parent->right = x;


		}
	}
	
	if(direction == "LEFT"){

		Node *parent = x->right;
		if(x == root){
			root = parent;
		}

		x->moveDown(parent);
		x->right = parent->left;

		if(parent->left != NULL){
			parent->left->parent = x;
			parent->left = x;


		}


	}



}










void RBTree::rotate(Node *&root, Node*&node, string direction){
	if(direction == "LEFT"){
		Node *temp = node->right; 
  
		node->right = temp->left; 
	  
		if (node->right != NULL){
			node->right->parent = node; 
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
	  
		temp->left = node; 
		node->parent = temp; 
	}
	
	if(direction == "RIGHT"){
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

}
void RBTree::fixInsert(Node *&root, Node *&node) 
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
					
					rotate(root, node->parent, "LEFT"); 
					node = node->parent;
					node->parent = node->parent;
					
				} 
  				//We have to rotate right around a's father if the node is on the 						parent's left 
				//subtree
				//Then we have to switch the color between the node's father and 					  grandfather
				if(node == node->parent->left){
                			
					rotate(root, node->parent->parent, "RIGHT");
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
					rotate(root, node->parent, "RIGHT"); 
					
					node = node->parent;
					node->parent = node->parent;
					
				} 
  				
				if(node == node->parent->right){
           
					rotate(root, node->parent->parent, "LEFT"); 
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
  
void RBTree::fixDelete(Node *node){ 
	if(node == root){
		
		return;
	}
	if(node->parent == NULL){
	
		node->sibling = NULL;
	}
	else{
		
		if(node == node->parent->left){
			
			node->sibling = node->parent->right;
		}
		if(node == node->parent->right){
			
			node->sibling = node->parent->left;
			cout << node->sibling->color << endl;

		}
	}

	if(node->sibling == NULL){
		
		fixDelete(node->parent);
	}
	
	else{
		
		if(node->sibling->color == "RED"){
			
			node->parent->color = "RED";
			node->sibling->color = "BLACK";
			if(node->sibling == node->parent->left){
				
				deleteRotate(node->parent, "RIGHT");
			
			}
			else{
				
				deleteRotate(node->parent, "LEFT");

			}
		
			fixDelete(node);
			
		}
	
		else{
			
			//if(node->sibling->left->color == "RED" || node->sibling->right->color == "RED"){
			if((node->sibling->left != NULL && node->sibling->left->color == "RED") || (node->sibling->right != NULL && node->sibling->right->color == "RED")){
				cout << "hello2" << endl;
				if(node->sibling->left != NULL && node->sibling->left->color == "RED"){
					cout << "hello44" << endl;
					if(node->sibling == node->parent->left){
						cout << "hello66" << endl;
						node->sibling->left->color = node->sibling->color;
						node->sibling->color = node->parent->color;
						deleteRotate(node->parent, "RIGHT");

					}
					else{
						node->sibling->left->color = node->parent->color;
						deleteRotate(node->sibling, "RIGHT");
						deleteRotate(node->parent, "LEFT");
			
					}
				}

				else{
					if(node->sibling == node->parent->left){
						node->sibling->right->color = node->parent->color;
						deleteRotate(node->sibling, "LEFT");
						deleteRotate(node->parent, "RIGHT");


					}
					else{
						node->sibling->right->color = node->sibling->color;
						node->sibling->color = node->parent->color;
						deleteRotate(node->parent, "LEFT");	


					}



				}

			node->parent->color = "BLACK";
			}
			else{
				node->sibling->color = "RED";
				if(node->parent->color == "BLACK"){
					fixDelete(node->parent);

				}
				else{
					node->parent->color = "BLACK";

				}

			}
	



		}








	}


	
	








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
	root = BinaryInsert(root, node); 
	fixInsert(root, node); 
} 


Node *replace(Node *node){
	if(node->left != NULL && node->right != NULL){
	 	Node *temp = node->right;
		while(temp->left != NULL){
			temp = temp->left;
		}
		return temp;
	}


	if(node->left == NULL && node->right == NULL){
		return NULL;
	}

	if(node->left != NULL){
		return node->left;
	}
	
	else{
		return node->right;

	}
}


Node* RBTree::search(int n){
	Node *temp = root;
	while(temp != NULL){
		if(n < temp->data){
			if(temp->left == NULL){
				break;

			}
			else{
				temp = temp->left;


			}


		}
		else if(n == temp->data){
			break;
		}
		
		else{
			if(temp->right == NULL){
				break;
			}
			else{
				temp =  temp->right;

			}

		}	


	}

	return temp;


}




void RBTree::deleteNode(Node *node){

	Node *temp = replace(node);

	if(node->parent == NULL){
		node->sibling = NULL;
	}
	else{
		if(node == node->parent->left){
			node->sibling = node->parent->right;
		}
		if(node == node->parent->right){
			node->sibling = node->parent->left;

		}
	}
	
	if(temp == NULL){
		if(node == root){
			root = NULL;
		}
		else{
			if((temp == NULL || temp->color == "BLACK") && (node->color == "BLACK")){
				fixDelete(node);	
			
			}
			else{
				if(node->sibling != NULL){
					node->sibling->color = "RED";
				}

			}

			if(node == node->parent->left){
				node->parent->left = NULL;
				
			}
			else{
				node->parent->right = NULL;
			}

		}
		delete node;
		return;

	}
	
	if(node->left == NULL || node->right == NULL){
		if(node == root){
			node->data = temp->data;
			node->left = node->right = NULL;
			delete temp;
		
		}
		else{
			if(node == node->parent->left){
				node->parent->left = temp;
		
			}
			else{
				node->parent->right = temp;
		
			}
			delete node;
			temp->parent = node->parent;

		
			if((temp == NULL || temp->color == "BLACK") && (node->color == "BLACK")){
				fixDelete(temp);
			

			}
			else{
				temp->color = "BLACK";

			}
		}
		return;

	}
	int tempvalue;
	tempvalue = node->data;
	node->data = temp->data;
	temp->data = tempvalue;
	deleteNode(temp);


}



void RBTree::deleteVal(const int &data){
	if(root == NULL){
		return;
	}

	Node *temp = search(data);
	deleteNode(temp);




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

		
	tree.deleteVal(6);
	cout << "\n" << endl;
	
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

	int data;

	while(getline(inputFile, line)){
		stringstream stringInput(line);
		string a;
		stringInput >> a;

		data = stoi(a);
		dataVector.push_back(data);
	}
	
	inputFile.close();

	for(int i = 0; i < dataVector.size(); i++){
		tree.insert(dataVector[i]);
	}
	

}


*/


























