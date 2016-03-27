#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define for(i,a,b) for(i=a;i<b;i++)
using namespace std;

int MAX(int a ,int b){
    return (a>b)? a:b;
}

int max_sum(int P[],int i,int sum){
    if(sum==0|| i<0 || sum < P[0])
        return 0;
    else if(sum<P[i])
        return max_sum(P,i-1,sum);
    else{
        return  MAX(P[i] + max_sum(P,i,sum-P[i]),max_sum(P,i-1,sum));
    }
}
int main() {
    int T,N,sum,A[2001],i;
    cin>>T;
    for(i,0,T)
    {
    cin>>N;
    cin>>sum;
     for(j,0,N)
         cin>>A[j];
       
     cout<<max_sum(A,N-1,sum)<<endl;
    }
    return 0;
}
