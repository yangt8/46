#include <iostream>
#include <fstream>
using namespace std;  
template <typename KeyType, typename ElementType>

class TreeNode
{
	KeyType key; 
	ElementType info;
	TreeNode * left, * right;

public:

	TreeNode(KeyType k, ElementType e, TreeNode *l, TreeNode *r)
          : key(k), info(e), left(l), right(r)
    {}


    static TreeNode * newNode(KeyType k, ElementType e, TreeNode * l, TreeNode * r)
    {
    	return new TreeNode(k, e, l, r);
    }


    static ElementType info_helper(TreeNode * t)  //2
    {
    	return t->info;  //2
    }

    static ElementType& operator_helper(TreeNode * t)  //3
    {
    	ElementType& r = t->info;  //2
        return r;    //1
    }

	static TreeNode * insert( KeyType key, ElementType info, TreeNode *RootT )     //1010logN+4
	{
		if ( !RootT )  //1
		{
			RootT = newNode(key, info, nullptr, nullptr);  //1001
		}
		TreeNode * t = RootT;    //1
		while ( t->key != key )      //2logN
		{
			if ( key < t->key )     //2logN
			{
				if (!t->left)    //2logN
				{
					t->left = newNode(key, info, nullptr, nullptr);     //1002logN
				}
				t = t->left;    //2logN
		    }
			else if ( key > t->key )     //2logN
		    {
			    if ( !t->right )    //2logN
			    {
			   		t->right = newNode(key, info, nullptr, nullptr);    //1002logN
			    }
			    t = t->right;     //2logN
		    }
		}
		t->info = info;      //2
		return RootT;        //1
	}


	static TreeNode * find(KeyType key, TreeNode * t)  //5logN+1
	{
		while ( t != nullptr )    //logN
			if ( key < t->key )    //2logN
				t = t->left;     //2logN
			else if ( key > t->key)   //2logN
				t = t->right;     //2logN
			else 
				return t;     //logN
		return nullptr;   //1
	}


	static TreeNode * remove(KeyType key, TreeNode * t ) 
	{
		if (!t)
			return nullptr;
		else if (key > t->key)
			t->right = remove(key, t->right);
		else if (key < t->key)
			t->left = remove(key, t->left);
		else
		{
			if ( t->left == nullptr && t->right == nullptr) 
			{
				delete t;
				return nullptr;
			}
			else if ( t->left == nullptr ) 
			{
				TreeNode * temp = t->right;
				delete t;
				return temp;
			}
			else if ( t->right == nullptr ) 
			{
				TreeNode * temp = t->left;
				delete t;
				return temp;
			}
			else 
		    { 
		    	TreeNode * predecessorNode = findPred(t);
		    	KeyType n = predecessorNode->key;
		        ElementType m = predecessorNode->info;
		    	t = remove(n,t);
		    	t->key = n;
		    	t->info = m;
		    }
		}
		return t;
	}


	static TreeNode * findPred(TreeNode * t ) 
	{
		t = t->left;
		while (t->right)
		{
			t=t->right;
		}
		return t;
	}


	static void deleteNode(TreeNode * t) 
	{
		delete t; 
	}


	static void deleteTree(TreeNode * t) 
	{
		if (t!=nullptr) 
		{
			deleteTree(t->left); 
			deleteTree(t->right); 
			deleteNode(t);
		} 
	}

	static void print(ostream & out, TreeNode * t) 
	{
		if ( t ) 
		{
			print(out, t->left);
			out << "      length " << t->key << ": " << t->info << " words\n"; 
			print(out, t->right);
		}
	}
};