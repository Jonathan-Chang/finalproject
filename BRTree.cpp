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
	

}

Node *root;







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





























