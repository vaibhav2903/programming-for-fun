#include<stdio.h>

#define MAX 30
int n,a[MAX],heap_size;
int Left(int k);
int Right(int i);
int Parent(int i);
void MAX_Heapify(int A[MAX], int i);

void BUILD_MAX_Heap(int A[MAX]);
void HEAPSORT(int A[MAX]);

int main(){
	
	int a[MAX],i,j;


	printf("enter the number of numbers\n");
	scanf("%d",&n);
	heap_size = n;
	for(i=1;i<=n;i++)
	{
scanf("%d",&a[i]);

	}
	HEAPSORT(a);
	for(j=1;j<=n;j++)
	{
		printf("%d\t",a[j]);

	}
	return 0;
}

int Left(int k)
{
	return 2*k;
}

int Right(int k){
	
	return 2*k +1;
}

int Parent(int i)
{
	return i/2;

}

void MAX_Heapify(int a[MAX], int i)
{
 int temp,l= Left(i);
 int r = Right(i);
int largest,j;
if(l<=heap_size && a[l]>a[i])
{largest = l;}

else{
	largest = i;
}

if(r<=heap_size && a[r] > a[largest])
{
	largest = r;
}

if(largest!=i)
{
  temp = a[i];
  a[i]= a[largest];
  a[largest] = temp;


MAX_Heapify(a,largest);
}

void BUILD_MAX_Heap(int a[MAX])
{
	int A_size = 0,i,j;

	A_size = heap_size;

	for(i=(A_size)/2;i>0;i--)
	{
	MAX_Heapify(a,i);
	}

	for(j=1;j<=n;j++)
	{
		printf("%d\t",a[j]);

	}

}


void HEAPSORT(int a[MAX])
{int k,temp,i;
	BUILD_MAX_Heap(a);
	
k = n;
	for(i= k;i>1;i--)
	{
	temp = a[i];
	a[i]= a[1];
	a[1]= temp;
heap_size = heap_size -1;
	MAX_Heapify(a,1);

	}

}

/*

void main(){

int *a,i,n;

printf("enter the no of numbers\n");
scanf("%d",&n);

a = (int *)malloc(n*sizeof(int));
i=0;
int j;
while(i<n)
{
	scanf("%d",&j);
	a[i] = j;
	
	i++;
}

printf("%d",a[0]);

}
*/
