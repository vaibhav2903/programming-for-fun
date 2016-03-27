#include <iostream>
#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;
void insertion_sort(int A[100],int N);
int main(){
	int N,A[100],i;
cout<< "Enter the number of numbers"<<endl;
cin>>N;
for(i,0,N){
	cin>> A[i];
}

// cout<<"What would you like to do?"<<endl;
// cout<<"1.Sort the array"<<endl;
// cout<<"2.search the array"<<endl;

// switch{
	insertion_sort(A,N);
 return 0;
}

void insertion_sort(int A[100],int N){

int i,j,key;
	for(i,1,N){
		key = A[i];
		j = i-1;
while(j>=0 && A[j]<key){
	A[j+1] = A[j];
	j= j-1;
}
A[j+1] = key;
	}
	cout<<"the sorted array is given by"<<endl;
	for(i,0,N){
		cout<<A[i]<<endl;
	}
	return;
}
