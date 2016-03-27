#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAX 10
#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;

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
int short_distance(int cost[MAX][MAX],int m,int n)
{
int dp[m][n],i,j;

dp[0][0] = cost[0][0];

for(i,1,m)
	dp[i][0] = dp[i-1][0] + cost[i][0];
for(j,1,n)
	dp[0][j] = dp[0][j-1] + cost[0][j];
for(i,1,m+1)
	for(j,1,n+1)
		dp[i][j] = Min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+cost[i][j];
	return dp[m][n];
}
int main(){
	int N,M,a,b,i,j;
		int A[10][10];
	cin>>M;
	cin>>N;
	for(i,0,M)
		for(j,0,N)
			cin>>A[i][j];
	cin>>a;
	cin>>b;
	cout<<short_distance(A,a,b)<<endl;
	return 0;
}