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
	int height;
	Node *left;
	Node *right;
	

};


Node *rotateRight(Node *node){
	Node *temp = node->left;
	Node *temp2 = node->right;
	int nodeHeightLeft = 0;
	int nodeHeightRight = 0;

	int tempHeightLeft = 0;
	int tempHeightRight = 0;
	
	temp->right = node;
	node->left = temp2;

	if(node->left != NULL){
		nodeHeightLeft = node->left->height;
	}
	
	else{
		nodeHeightLeft = 0;
	}

	if(node->right != NULL){
		nodeHeightRight = node->left->height;

	}	
	
	else{
		nodeHeightRight = 0;
	}
	
	if(temp->left != NULL){
		tempHeightLeft = temp->left->height;
	}

	else{
		tempHeightLeft = 0;
	}

	if(temp->right != NULL){
		tempHeightRight = temp->right->height;

	}

	else{
		tempHeightRight = 0;
	}
	



	node->height = max(nodeHeightLeft, nodeHeightRight)+1;
	temp->height = max(tempHeightLeft, tempHeightRight)+1;

	return temp;


}

Node *rotateLeft(Node *node){
	Node *temp = node->left;
	Node *temp2 = node->right;
	int nodeHeightLeft = 0;
	int nodeHeightRight = 0;

	int tempHeightLeft = 0;
	int tempHeightRight = 0;
	
	temp->left = node;
	node->right = temp2;

	if(node->left != NULL){
		nodeHeightLeft = node->left->height;
	}
	
	else{
		nodeHeightLeft = 0;
	}

	if(node->right != NULL){
		nodeHeightRight = node->left->height;

	}	
	
	else{
		nodeHeightRight = 0;
	}
	
	if(temp->left != NULL){
		tempHeightLeft = temp->left->height;
	}

	else{
		tempHeightLeft = 0;
	}

	if(temp->right != NULL){
		tempHeightRight = temp->right->height;

	}

	else{
		tempHeightRight = 0;
	}
	



	node->height = max(nodeHeightLeft, nodeHeightRight)+1;
	temp->height = max(tempHeightLeft, tempHeightRight)+1;

	return temp;

}




Node *insert(Node *node, int value){

	if(node == NULL){
		Node *newNode = new Node();
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->height = 1;
		return newNode;
	}

	if(value < node->value){
		node->left = insert(node->left, value);

	}
	
	else if(value > node->value){
		node->right = insert(node->right, value);

	}
	
	else{
		return node;
	}


	node->height = 1 + max(node->left->height, node->right->height);
	
	int balance = (node->left->height) - (node->right->height)
	
	
	if(balance > 1){
		if(value < node->left->value){
			return rotateRight(node);
		}
		else{
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}
	}
	
	if(balance < -1){
		if(value > node->right->value){
			return rotateLeft(node);
		}
		
		else{
			node->right = rotateRight(node->right);
			return rotateLeft(node);

		}	



	}
	

	return node;



}



vector<int> valueVector;

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
