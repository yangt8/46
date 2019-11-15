#include <iostream>
#include <fstream>
#include "TreeNode.cpp"
using namespace std;  
template <typename KeyType, typename ElementType>


class BinarySearchTree
{
	TreeNode<KeyType, ElementType> * root;
	
public:
	
	BinarySearchTree()
          : root(nullptr)
    {}

    ~BinarySearchTree()
    {
    	TreeNode<KeyType, ElementType>::deleteTree(root);
    }


    void countLengths(KeyType key)
    {
    	TreeNode<KeyType, ElementType> * t = TreeNode<KeyType, ElementType>::find(key, root); 
    	if (t)
    	{
    		KeyType& l = TreeNode<KeyType, ElementType>::operator_helper(t);
    		l++;
    	}
    	else
    		root = TreeNode<KeyType, ElementType>::insert(key, 1, root); 
    }


    ElementType & operator[] (KeyType s)    //1020logN+14
    {
    	TreeNode<KeyType, ElementType> * t = TreeNode<KeyType, ElementType>::find(s, root);   //5logN+2
    	if (t)  //1
    		return TreeNode<KeyType, ElementType>::operator_helper(t); //4
    	else
    	{
    		insert(s, 0);       //1010logN+5
	 	    TreeNode<KeyType, ElementType> * t2 = TreeNode<KeyType, ElementType>::find(s, root);  //5logN+2
	 	    return TreeNode<KeyType, ElementType>::operator_helper(t2);   //4
    	}
    }


	void insert(KeyType key, ElementType info)       //1010logN+5
	{
		root = TreeNode<KeyType, ElementType>::insert(key, info, root); //1010logN+4
	}


	ElementType find(KeyType key)      //1020logN+13
	{
		TreeNode<KeyType, ElementType> * t = TreeNode<KeyType, ElementType>::find(key, root);   //5logN+2
	 	if ( !t )  //1
	 	{
	 		insert(key, 1);     //1010logN+5
	 		t = TreeNode<KeyType, ElementType>::find(key, root);   //5logN+2
	 	}
	 	return TreeNode<KeyType, ElementType>::info_helper(t);     //3
	}

	void remove(KeyType key) 
	{
		root = TreeNode<KeyType, ElementType>::remove(key, root); 
	}

	void print(ostream & out) 
	{
		TreeNode<KeyType, ElementType>::print(out, root); 
	}

};