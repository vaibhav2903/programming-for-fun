#include <iostream>
#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;
int Min(int a, int b){
	return (a>b)? a:b;
}

int binomial_coeff(int n,int k)
{
	if(k==0 || k==n)
	return 1;
	else{
	return binomial_coeff(n-1,k-1) + binomial_coeff(n-1,k);
	}
}
int nCk(int n,int k){
	int C[n+1][n+1],i,j;
	for(i,0,n+1)
		for(j,0,Min(i,k)+1)
	{
		if(i==j || j==i)
		C[i][j] = 1;
	else{
		C[i][j] = C[i-1][j] + C[i-1][j-1];
	}

	}
	return C[n][k];
}
int main(){
	int N,k;
	cin>>N;
	cin>>k;
	cout<<nCk(N,k)<<endl;
	cout<<binomial_coeff(N,k)<<endl;
	return 0;
}