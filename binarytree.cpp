#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;

struct node{
	int key;
	struct node* left;
	struct node* right;
struct node* parent;
}root;



void INORDER_WALKTREE(struct node x)
{
	if(x != NULL)
	{
INORDER_WALKTREE(x->left);
cout<<x.key;
INORDER_WALKTREE(x->right);
	}

}

struct node TREE_SEARCH(struct node x,int k)
{

		if(x.key== k || x== NULL)
		{
return x;
		}
		elseif(x.key< k)
		{
			return TREE_SEARCH(x->left,k);
		}

		else{
			return TREE_SEARCH(x->right,k);
		}
	}
struct node TREE_MIN(struct node x)
{
while(x->left!=NULL)
{	x = x->left;
}
return x;
}

struct node TREE_SUCCESR(struct node x)
{
	if(x.right!= NULL)
		{return TREE_MIN(x->right);}
y = x.p;
while(x!=NULL && x==y->right)
{
	x = y;
	y = y.p;
}
return y;
}

void TREE_INSERT(struct node T,struct node z)
{
struct node x,y;
y =NULL;
x = T;
while(x!=NULL)
{
y = x;
	if(x.key<z.key)
	{
		x = x->left;
	}
	else{
		x= x->right;
	}
}
z.p = y;

if(y==NULL)
{
	T = z;
}

elseif(z.key<y.key)
{
	y->left = z;
}

else{
	y->right = z;
}
}



int main(){
	int n;
	cout<<"enter the value of n";
	cin>>n;
	cout<<"insert in the binary tree\n";
struct node z;
   while(i<n)
  { cin>>z.key;
	TREE_INSERT(root,z);
}

}





