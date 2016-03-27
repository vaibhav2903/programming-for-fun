#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#define lli long long int
#define for(i,a,b) for(i=a;i<b;i++)
using namespace std;

lli A[100000],B[100000],C[100000];
bool rel_seq(lli A[],lli B[],int N){
    C[0] = min(A[0],B[0]);
    int i=0;
    while(i<N){
        if((A[i]<C[i-1]) && (B[i]<C[i-1]))
           return false;
   else if((A[i]>C[i-1]) && (B[i]<C[i-1]))
            {C[i] = A[i];}
   else if((A[i]<C[i-1]) && (B[i]<C[i-1]))
            {C[i] = B[i];}
   else if((A[i]>C[i-1]) && (B[i]>C[i-1]))
        {  if( i== N-1)
            C[i] = max(A[i],B[i]);
            else{
            C[i] = min(A[i],B[i]);
        }
     }
    i++;
        cout<<"t"<<endl;
    }
    return true;
}

int main() {
    int T,N,i,j,k;
      cin>>T;
    for(j,0,T)
       { 
        cin>>N;
        //cout<<j<<"th one"<<endl;
        for(i,0,N)
            cin>> A[i];
       for(i,0,N)
            cin>>B[i];   
        //k = rel_seq(A,B,N);
        //cout<<k<<endl;
    if(rel_seq(A,B,N))
        cout<<"YES"<<endl;
    else 
    {cout<<"NO"<<endl;}
    }
    return 0;
}