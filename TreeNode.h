// TreeNode.h - TreeNode class declaration
// Written by Varun Patel
#include<string>

template<typename DATA_TYPE>
struct TreeNode
{
	// Constructor
	TreeNode(const DATA_TYPE& value, TreeNode* left = NULL, TreeNode* right = NULL)
   {
      Value = value;
      Left = left;
      Right = right;
	}

   DATA_TYPE Value;
   TreeNode* Left;
   TreeNode* Right;

   // Create the Leaf. If there is a point where the right node is NULL and 
   // the left node is also NULL- this is the leaf
   bool IsLeaf() const
   {
      return Left == NULL && Right == NULL;
   }

   // Determine if parent has one child- if either left node OR right node is null, then
   // OnlyOneChild
   bool OnlyOneChild() const
   {
	   return (Left == NULL) || (Right == NULL);
   }
};


template<typename DATA_TYPE>
// Delete Function declaration and Implementation
// This function finds Data in the Root and Deletes it
// If the Data is not found, return false
bool Delete(TreeNode<DATA_TYPE>*& root, const DATA_TYPE& data)	
{
	// Data is not found in the tree, return false
	if (root == NULL)
		return false;

	// If Data is found, delete it
	else
	if (root->Value == data)
	{
		// Case # 1- If the node is a Leaf, - delete it and set the pointer to NULL
		if (root->IsLeaf())
		{
			delete root;
			root = NULL;
			return true;
		}
		else
		// Case # 2- If the node has only one child, delete it
		// replace the deleted with the pointer to it's only child
		if (root->OnlyOneChild())
		{
			if (root->Left != NULL)	
			{
				TreeNode<string>* right = root->Left;
				delete root;
				root = right;
			}
			else
			{	
				TreeNode<string>* left = root->Left;
				delete root;
				root = left;
			}
		}
		else
		// Case # 3- If the node has two children then replace its value with 
		// the value of the right-most node from its left sub-tree
		{
			// In the left sub tree, find the right most node
			TreeNode<string>* temp = root->Left;
			while (temp->Right!=NULL)
				temp = temp->Right;

			// Set the value of the root
			root->Value = temp->Value;

			// Delete the right most node that was found
			Delete(root->Left, temp->Value);
			return true;
		}
	}
	else
	// If not found, keep searching deeper
	if (root->Value > data)
		Delete(root->Left, data);
	else
		Delete(root->Right, data);
}

template<typename DATA_TYPE>
// Print Function- Prints the Tree recursively
void Print(TreeNode<DATA_TYPE>* root)
{
	if (root==NULL)
		return;
	else

	if (root->IsLeaf())
		cout<< root->Value<<endl;
	else
	{
		Print(root->Left);
		cout << root->Value << endl;
		Print(root->Right);
	}
}

template<typename DATA_TYPE>
// Insert Function implementation
void Insert(TreeNode<DATA_TYPE>*& root, const DATA_TYPE& insertData)
{
	// Insert Data
	if (root == NULL)
	{
		// Allocate memory on the heap for insertData
		root = new TreeNode<string>(insertData);
		return;
	}
	// Figure out where to Insert
	if (root->Value > insertData)
		Insert(root->Left, insertData);
	else
		Insert(root->Right, insertData);
}