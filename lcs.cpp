#include <iostream>
#include <cstdio>
#include <cstdlib>
#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;
int max(int a,int b){
	return (a>b)? a:b;
}

int lcs(char A[],char B[],int N,int M){
	int i,L[N+1][M+1],j;
	for(i,0,N+1)
		for(j,0,M+1)
			{
				if(i==0 || j==0)
				L[i][j] = 0;

			else if(A[i-1] == B[j-1])
				L[i][j] = 1 + L[i-1][j-1];
			

			else{
				L[i][j] = max(L[i-1][j],L[i][j-1]);
				}
			
			}

	return L[N][M];
}

int Min(int A,int B,int C){
	int MIN;
	if(A<=B)
		MIN = A;
	else 
		{MIN = B;}

	if(C<MIN)
		MIN = C;
	
	return MIN;
}
int LCS(char A[],char B[],int N, int M)
{
	int i,j,D[N+1][M+1];

	for(i,0,N+1)
		for(j,0,M+1)
		{
			if(i==0)
				D[i][j] = j;
			else if(j==0)
				D[i][j] = i;
			else if(A[i-1]== B[j-1])
				D[i][j] = D[i-1][j-1];
			else{
				D[i][j] = 1 + Min(D[i][j-1],D[i-1][j],D[i-1][j-1]);
			}
		}

		return D[N][M];

}

int main(){
int N,M,i,j;
cin>>N;
cin>>M;
char A[N],B[M];
for(i,0,N)
	cin>>A[i];
for(i,0,M)
	cin>>B[i];
cout<<lcs(A,B,N,M)<<endl;
cout<<LCS(A,B,N,M)<<endl;
return 0;
}