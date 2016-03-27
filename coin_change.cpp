#include <iostream>
#include <cstdlib>
#include <cstdio>
#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;

int count(int S[],int m,int n)
{
	int i,j,x,y;
	int table[n+1][m];
	for(i,0,m)
		table[0][i] = 1;

	for(i,1,n+1)
		for(j,0,m){
			x = (i-S[j]>= 0)? table[i-S[j]][j]:0;
			y = (j>=1)? table[i][j-1]:0;

			table[i][j] = x+y;
		}

		return table[n][m-1];
}

	int main()
	{
	int i,M,N;
	cin>>M;
	int S[M];
	for(i,0,M)
		cin>>S[i];

	cin>>N;
	cout<<count(S,M,N);
return 0;
}