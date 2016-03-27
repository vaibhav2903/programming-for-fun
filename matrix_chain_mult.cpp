#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;
int Min_cost(int P[],int i,int j){
	if(i==j)
		return 0;
	int k,count,Min;
	Min = INT_MAX;
	for(k,i,j)
		{
			count = Min_cost(P,i,k) + Min_cost(P,k+1,j) + P[i-1]*P[k]*P[j];
			if(count<Min)
				Min = count;
			}
			return Min;
}

int MIN_cost(int P[],int N){
	int i,j,m[N][N],MIN_,L,k;
	for(i,0,N)
		m[i][i] = 0;

	for(L,2,N)
		for(i,1,N-L+2)
	{	
		j = i+L-1;
		m[i][j] = INT_MAX;
		for(k,i,j)
		{
			MIN_ = m[i][k] + m[k+1][j] + P[i-1]*P[k]*P[j];
			if(MIN_<m[i][j])
				m[i][j]=MIN_;
		}
	}
	return m[1][N-1];
}

int main(){
	int N,i;
	cin>>N;
	int A[N];
	for(i,0,N)
	cin>>A[i];

cout<<Min_cost(A,1,N-1)<<endl;
cout<<MIN_cost(A,N-1)<<endl;
return 0;
}