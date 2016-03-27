//longest subsequence
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#define for(i,a,b) for(i=a;i<b;i++)
using namespace std;

int lis(int arr[],int n)
{
	int i,j;
	int* lis = (int*)malloc(n*sizeof(int));
	for(i,0,n)
	lis[i] =1;
	
	for(i,0,n)
		for(j,0,i)
			if(arr[i]>arr[j] && lis[i]<lis[j]+1)
				lis[i] = lis[j] + 1;
	int max=0;
	for(i,0,n)
		if(lis[i]>max)
			max = lis[i];
free(lis);
return max;
}

int main(){
int N,i;

cin>>N;
int A[N];
for(i,0,N)
{
	cin>>A[i];
}

cout<<lis(A,N)<<endl;

return 0;
}