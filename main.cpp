// main.cpp - Binary Search Tree program main entry point
// Written by Varun Patel

#include <iostream>
#include <string>
#include "TreeNode.h"

using namespace std;

void main()
{
	TreeNode<string>* rootNode = NULL;
	// Declare myWord and deleteWord of type string
	string myWord;
	string deleteWord;

	cout << "Enter a sentence: " << endl;
	cout << endl;

	// To separate words in sentence use >> operator cin.peek()
	while ( cin.peek() != '\n' )
	{   
		// Capture user input sentence in myWord
		cin >> myWord;
		// use Insert function to insert words into BST
		Insert<string>(rootNode, myWord);
	}

	// Binary Search Tree- Print words from sentence that was input
	cout << "The Binary Search Tree Sorted Result from the sentence that you input is:" << endl;
	// Print the BST using the Print function
	Print<string>(rootNode);
	cout << endl;

	// Testing the delete function
	cout << "What word would you like to delete from your sentence? " << endl;
	cin >> deleteWord;
	cout << endl;

	// There are two cases, if the word was found, print
	// if not, let the user know the word was not found and print
	if (Delete<string>(rootNode, deleteWord))
	{
		cout << "'"<< deleteWord << "'"<< " was deleted. Here is your new BST: " << endl;
		Print<string>(rootNode);
	}
	else
	{
		cout << "'"<< deleteWord << "'"<< " was not found. Here is your BST: " << endl;
		Print<string>(rootNode);
	}

	cout << endl;
	system("pause");
}