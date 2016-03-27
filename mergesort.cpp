#include <iostream>
#define for(i,a,b) for(i=a;i<=b;i++)

using namespace std;
void merge(int A[100],int p,int k,int r);
void merge_sort(int A[100],int p,int q);
bool binary_search(int A[1000],int key,int low,int high);
bool sum_exists(int A[],int N, int x);
int main(){

int X,N,A[100],i;

cout<<"Enter the value of N"<<endl;
cin>>N;

for(i,1,N){
	cin>>A[i];
}

cout<<"Enter the sum you want to know if its possible"<<endl;
cin>>X;
merge_sort(A,1,N);
bool t  = sum_exists(A,N,X);
if(t ==true){
   cout<<"the sum exists"<<endl;
}
else{
   cout<<"the sum doesn't exist"<<endl;
}

for(i,1,N){
	cout<<A[i]<<endl;
}
return 0;

}

void merge_sort(int A[100],int p,int q){

	if(p<q)
	{
		int k = (p+q)/2;
		merge_sort(A,p,k);
		merge_sort(A,k+1,q);
		merge(A,p,k,q);
	}


}

void merge(int A[100],int p,int k, int r){

int n1 = k-p+1; int n2 = r-k;
int i,L[100],R[100],j,m;

for(i,1,n1){
	L[i]=A[p+i-1];
}
   for(i,1,n2){
   	R[i] = A[k+i];
   }

   L[n1+1] = 1000000; R[n2+1] = 10000000;

   i=1;j=1;

   for(m,p,r){

   	if(L[i]<=R[j])
   		{A[m] = L[i];
   	i++;}
   	else{
   		A[m]=R[j];
   		j++;
   	}
   }
   return;

}


bool binary_search(int A[1000],int key,int low,int high){
bool flag = false;
int mid;



if(low >= high){
   return flag;
}
mid = (low +high)/2;
 if(A[mid]==key){
   flag = true; 
   return flag;
}

else if(A[mid]>key){
   return binary_search(A,key,low,mid);
}

else{
   return binary_search(A,key,mid+1,high);
}

}

bool sum_exists(int A[],int N, int x){
int i;bool t = false;
for(i,0,N){
   if(binary_search(A,x-A[i],0,N)!= false)
   {
     t = true; 
     return t;  
   } 
}

}