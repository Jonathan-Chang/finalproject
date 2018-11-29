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



struct Node {
	int value;
	Node *left;
	Node *right;
	Node *parent;
	Node *uncle;
	Node *grandparent;
	string color;
	
	


};


void inorder(Node *root){

	if(root == NULL){
		return NULL;
	}
	
	inorder(root->left);	
	cout << root->value << endl;
	inorder(root->right);
}

Node* insert(Node *root, Node* node){
	if(root == NULL){
		return node;
	}
		
	else{
		if(node->value < root->value){
			root->left = insert(root->left, node);
		}
		else{
			root->right = insert(root->right, node);

		}


	}
	return root;
}




void rotateLeft(Node *&root, Node *&pt){
	Node *temp = pt->right;
	
	pt->right = temp->left;
	
	if(pt->right !=	NULL){
		pt->right->parent = pt;

	}
	
	temp->parent = pt->parent;
	
	if(pt->right == NULL){
		root = temp;

	}
	
	else if (pt == pt->parent->left){
		pt->parent->left = temp;
	}
	
	else{
		pt->parent->right = temp;

	}
	
	temp->left = pt;
	pt->parent = temp;
	
}

void rotateRight(Node *&root, Node *&pt){
	Node *temp = pt->left;
	
	pt->left = temp->right;
	
	if(pt->left !=	NULL){
		pt->left->parent = pt;

	}
	
	temp->parent = pt->parent;
	
	if(pt->parent == NULL){
		root = temp;

	}
	
	else if (pt == pt->parent->left){
		pt->parent->left = temp;
	}
	
	else{
		pt->parent->right = temp;

	}
	
	temp->right = pt;
	pt->parent = temp;
	
}


void insertFix(Node *&root, Node *&pt){


	Node *tempParent = NULL;
	Node *tempGrand = NULL;


	while((pt != root) && (pt->color != "black") && (pt->parent->color == "red"){
		
		tempParent = pt->parent;
		tempGrand = pt->parent->parent;


		if(pt->uncle == "red"){
			pt->father->color = "black";
			pt->uncle->color = "black";
			if(pt->father != root){
				pt->father == "red";
			}
		}

		if(pt->uncle == "black" && pt->value > pt->parent->value){
			rotateLeft(root, pt->parent);
			pt = tempParent;
			tempParent = pt->parent;
		}
		
		if(pt->uncle == "black" && pt->value < pt->parent->value){
			


		}
		
	
	
	}




}










int main(int argc, char* argv[]){



            /*********************** Read input file *************************/


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
	

}





























