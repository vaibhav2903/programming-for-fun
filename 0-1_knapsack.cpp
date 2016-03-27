#include <iostream>
#include <cstdlib>
#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;
int MAX(int a,int b)
{
	return (a>b)?a:b;
}
int zero_one(int W[],int val[],int w,int n)
{
	if(n==0 || w==0)
		return 0;
	else if(W[n-1]> w)
		return zero_one(W,val,w,n-1);
	else{
		return MAX(val[n-1] + zero_one(W,val,w-W[n-1],n-1),zero_one(W,val,w,n-1));
	}

}

int knapsack01(int W[],int val[],int wt,int n)
	{
		int i,w;
		int K[n+1][wt+1];

		for(i,0,n+1)
			for(w,0,wt+1)
			{
				if(i==0 || wt==0)
					K[i][w] =0;
				else if(W[i-1]<=wt)
					K[i][w] = max(val[i-1] + K[i-1][w - W[i-1]],K[i-1][w]);
				else{
					K[i][w] = K[i-1][w];
				} 
			}
		return K[n][wt];
	}
int main(){
int A[] = {10,20,30};
int val[] = {60,100,120};
int W = 50;
cout<<knapsack01(A,val,W,3)<<endl;
cout<<zero_one(A,val,W,3)<<endl;
return 0;
}