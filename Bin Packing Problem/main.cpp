#include <iostream>
#include "binarySearchTree.h"
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	bSearchTreeType<double> firstTreeRoot;
	bSearchTreeType<double> bestTreeRoot;
	double weight;
	int count = 1;

	ifstream infile;
	infile.open("Weights.txt");

	if (!infile)                               
	{
		cout << "The input file does not "
			<< "exist. Program terminates!"
			<< endl;
		return 1; //exit if input file doesn't exist
	}

	infile >> weight; //get the weight of the first object
	while (infile)
	{
		if (weight > 1) //if weight > 1, notify user
			cout << "Object weight must not be greater than 1 kg. Object " << count << " will not be processed." << endl;
		else
		{
			firstTreeRoot.firstFit(weight); //using first-fit algorithm
			bestTreeRoot.bestFit(weight); //using best-fit algorithm
		}
		infile >> weight; //get the weight of the next object
		count++;
	}

	cout << endl << "Using the first-fit heuristic: " << endl; //first-fit heuristic
	cout << "Bin weights in inorder: ";
	firstTreeRoot.inorderTraversal();
	cout << endl << "Bin weights in preorder: ";
	firstTreeRoot.preorderTraversal();
	cout << endl << "Bin weights in postorder: ";
	firstTreeRoot.postorderTraversal();
	cout << endl << "Number of bins used: "
		<< firstTreeRoot.treeNodeCount() << endl << endl;
	
	cout << endl << "Using the best-fit heuristic: " << endl; //best-fit heuristic
	cout << "Bin weights in inorder: ";
	bestTreeRoot.inorderTraversal();
	cout << endl << "Bin weights in preorder: ";
	bestTreeRoot.preorderTraversal();
	cout << endl << "Bin weights in postorder: ";
	bestTreeRoot.postorderTraversal();
	cout << endl << "Number of bins used: "
		<< bestTreeRoot.treeNodeCount() << endl << endl;
	
	cin.get();
}