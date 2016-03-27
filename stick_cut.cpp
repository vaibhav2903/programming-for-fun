#include <iostream>

#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;

int least_positive_int(int A[1000],int N){
      int key = 1001;int i ;
      // while(i<N && A[i]<key && A[i]>0 && key!=0){
      // 	key = A[i];
      // 	i++;
      // }
      for(i,0,N){
if(A[i]<key && A[i]!= 0 && key!=0 )
      {key = A[i];}
  }
    if(key ==0){
      return -1;
    }
return key;

}
int stick_cut(int A[1000],int N){

int m,count=0;int B[1000],i;
int k = least_positive_int(A,N);

if(k==-1){
  return 0;
}
//cout<<k<<endl;

else{
for(i,0,N){

if(A[i]>0){
     *(A+i) -= k;
     count++;
}

}
// for(i,0,N){
// 	cout<<A[i];
// }
return count;
}

}

int main(){
	int N,A[1000],i;
	cin>>N;
int count = N;
	for(i,0,N){
       cin>>A[i];
	}
  
//cout<<count<<endl;
while(count!= 0){
   count = stick_cut(A,N);

if(count!=0) 
  {
    cout<<count<<endl;
}
}
}

// for(i,0,N){
//  cout<<A[i];
//   }

//    cout<<count<<endl;
// count = stick_cut(A,N);
// for(i,0,N){
//  cout<<A[i]; }
//  cout<<endl;
//  cout<<count<<endl;
// count = stick_cut(A,N);
// for(i,0,N){
//  cout<<A[i]; }
//   cout<<endl;
//  cout<<count<<endl;

//  count = stick_cut(A,N);
// for(i,0,N){
//  cout<<A[i]; }
//   cout<<endl;
//  cout<<count<<endl;

//  count = stick_cut(A,N);
// for(i,0,N){
//  cout<<A[i]; }
//   cout<<endl;
//  cout<<count<<endl;


   //while(count!=0){
   //count = stick_cut(A,N);
   //cout<<count<<endl;}


