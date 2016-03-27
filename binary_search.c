
#include<stdio.h>

#define MAX 30 
void binary_search(int a[MAX],int key,int n);
void bubblesort(int a[MAX],int n);

int main(){
	int a[MAX],i, j, n;

	printf("enter the number of numbers\n");
	scanf("%d",&n);
i=0;
printf("enter the numbers\n");
	for(i=0;i<n;i++)
	{
scanf("%d",&a[i]);
	}
bubblesort(a,n);
int key =0;
printf("enter the key to be found\n");
scanf("%d",&key);
binary_search(a,key,n);

return 0;
}

void bubblesort(int a[MAX],int n)
{
	int i,j,temp;

	for(i=0;i<n;i++)
	{
for(j=0;j<i;j++)
{
	if(a[j]<a[j+1])
	{
	temp = a[j];
	a[j]= a[j+1];
	a[j+1]= temp;
	}

}


	}
	for(i=0;i<n;i++)
{
 printf("\n%d",a[i]);

}



}

void binary_search(int a[MAX],int key,int n)
{
  int i, j,low,mid,high;
low = 0;
high = n;
do{
mid = (low +high)/2;
if(a[mid]>key)
{
 high = mid-1;
}
else if(a[mid]<key)
{
	low = mid+1;
}


}while(a[mid]!= key && low>=high);

 if(a[mid] == key)
{
  printf("the element has been found\n");

}

else if(a[mid]!=key)
{
	printf("the element was not found\n");
}


}
