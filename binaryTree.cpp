#include <iostream>
#include <stdlib.h>
using namespace std;

struct Treenode{

	int key;
	struct Treenode *left;
	struct Treenode *right;

	Treenode(int k)
	{
		key = k;
		left = NULL;
		right = NULL;
	}

};
struct Treenode *root = NULL;



void printInorderTree(struct Treenode *root)
{
	if(root!=NULL)
	{
		printInorderTree(root->left);
		cout<<root->key<<std::endl;
		printInorderTree(root->right);
	}
}


bool search( struct Treenode *root, int key)
{
	if(root==NULL)
	{
		return false;
	}
	if(root->key==key)
	{
		return true;
	}
	else if(root->key > key)
	{
		return search(root->left,key);
	}
	else if (root->key<key)

	{
	return search(root->right,key);
	}

}

void Treeinsert(struct Treenode *(&root), int key)
{
if(root==NULL)
{
	root = new Treenode(key);
}

else if(key < root->key)
{
	Treeinsert(root->left,key);
}

else if(key>root->key)
{
	Treeinsert(root->right,key);
}

}

	 void Treedelete(struct Treenode *(&root) ,int key)
	 {
		bool m;
		m = false;
			struct Treenode *current = root; 
		struct Treenode *predecessor = NULL;

	   while(current!=NULL || m == true)
	   {
	   	if(key==current->key)
	   	{
	     m = true;
	   	}
	else if(key <current->key)
		{
			predecessor = current;
		current=current->left;
	}
	else
	{   predecessor = current;
		current = current->right;
	}
	}
		// searching ends
if(m==false)
	{
		cout<<"the element is not present\n"<<endl;
}
else if(m==true)
	{
	if((current->left == NULL && current->right !=NULL) || (current->right ==NULL && current->left != NULL))
	{
		if(current->left ==NULL && current->right != NULL)
		{
	if(predecessor->left == current)
	{
	predecessor->left = current->right;
	free(current);
	current = NULL;
	cout<<key<<" has been removed from the Tree."<<endl;
	cout<<"testing"<<endl;
	}
	else if(predecessor->right == current)
	{
		predecessor->right = current->right;
		free(current);
		current=NULL;
		cout<<key<<" has been removed from the Tree."<<endl;
		cout<<"testing"<<endl;

	}
	}
	//case:2
	else if(current->left != NULL && current-> right == NULL)
	{
	if(predecessor->left ==current)
	{
	predecessor->left = current->left;
	free(current); current = NULL;
	cout<<key<<" has been removed from the Tree."<<endl;
	cout<<"testing"<<endl;

	}
	else if(predecessor->right == current)
	{
		predecessor->right = current->right;
	free(current); current = NULL;
	cout<<key<<" has been removed from the Tree."<<endl;
	cout<<"testing"<<endl;

	}
	}
}
	// case 3:
	else if(current->left== NULL && current->right == NULL)
	{
	if(predecessor->left == current)
	{
		predecessor->left = NULL;
		cout<<key<<" has been removed from the Tree."<<endl;
		cout<<"testing"<<endl;

	}
	else if(predecessor->right == current)
	{
		predecessor->right = NULL;
		cout<<key<<" has been removed from the Tree."<<endl;
		cout<<"testing"<<endl;

	}
	}
	// case 4:

 if(current->left != NULL && current->right != NULL)
	{
	// 		Treenode* check=current->right;
	// 		if((current->left==NULL)&&(current->right==NULL))
	// 		{
	// 			current=check;
	// 			free (check);
	// 			current->right==NULL;
	// 			cout<<key<<" has been removed from the Tree."<<endl;
	// 			cout<<"testing"<<endl;

			}
			else // Right child has children
			{
				// If the node's right child has a left child
				// Move all the way down left to locate smallest element
				if((current->right)->left!=NULL)
				{
					struct Treenode* leftCurrent;
					struct Treenode* leftCurrentPred;
					leftCurrentPred=current->right;
					leftCurrent=(current->right)->left;
					while(leftCurrent->left != NULL)
					{
						leftCurrentPred=leftCurrent;
						leftCurrent=leftCurrent->left;
					}
					current->key=leftCurrent->key;
					 free(leftCurrent);
					leftCurrentPred->left==NULL;
					cout<<key<<" has been removed from the Tree."<<endl;
					cout<<"testing"<<endl;

				}
				else
				{
					struct Treenode* temp=current->right;
					current->key=temp->key;
					current->right=temp->right;
					 free(temp);
					cout<<key<<" has been removed from the Tree."<<endl;
					cout<<"testing"<<endl;

				}
			}
		}

}


int main(){
int n,temp,i,item;

	cout<<"enter the number of values to be inserted\n"<<std::endl;
	cin>>n;
	cout<<"enter the numbers"<<std::endl;
	for(i=0;i<n;i++)
{
	cin>>temp; 
Treeinsert(root,temp);
}
cout<<"the inserted numbers are\n";
 printInorderTree(root);

cout<<"enter the element to be searched\n"<<std::endl;
cin>> item;
bool m;
m = search(root,item);
if(m == true)
{
	cout<<"number found"<<std::endl;
}

else{
	cout<<"element not found\n";
}

cout<<"enter the element to be deleted\n"<<std::endl;
cin>>item;
Treedelete(root,item);

printInorderTree(root);
return 0;
}
