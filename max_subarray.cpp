#include <iostream>
#define fr(i,a,b) for(i=a;i<b;i++)
#define MAX 100000
using namespace std;
void modulo(long long int A[],long long int N,long long int M);
long long int find_max_crossing_subarray(long long int A[],long long int low,long long int mid,long long int high,long long int M);
long long int find_max_modulo_subarray(long long int A[],long long int low,long long int high,long long int M);

	int main(){
	     
		      long long int A[MAX],N,M,t,i,T,k;
		      cin>>T;
		      fr(k,0,T){
		      	cin>>N;
		      cin>>M;
		      fr(i,0,N){
		      	cin>> A[i];

		      }
		            modulo(A,N,M);
				t = find_max_modulo_subarray(A,0,N-1,M);
				cout<<t<<endl;
			}
	}

	void modulo(long long int A[MAX],long long int N,long long int M){
	long long int i;
	fr(i,0,N){
		A[i]= A[i]%M;
		//cout<<A[i]<<endl;
	}

	}

	long long int find_max_crossing_subarray(long long int A[MAX],long long int low,long long int mid,long long int high,long long int M){
	long long int i,left_sum = -1; long long int max_sum = 0;
	long long int sum = 0;

	for(i = mid;i>=low;i--){

		sum = sum + A[i];

		sum = sum % M;
		if(sum > left_sum){
			left_sum = sum;
			//cout<<left_sum<<endl;
		}
	}
	//cout<<"the max sum is "<<left_sum<<endl;

	long long int right_sum = -1; sum = 0;
	for(i= mid+1;i<=high;i++){
		sum = sum +A[i];
		sum = sum % M;
		if(sum>right_sum){
			right_sum = sum;
			//cout<<right_sum<<endl;
		}
	}
		//cout<<"the max sum is " <<right_sum<<endl;

	max_sum = ( left_sum + right_sum ) % M;
	//cout<<"the variable max_sum is " <<max_sum<<endl; 

	if(left_sum >= right_sum && left_sum >= max_sum)
	{ return left_sum; }
else if (right_sum >= left_sum && right_sum >= max_sum ){
	return right_sum;
}
else{
	return max_sum;
}

	}

	long long int find_max_modulo_subarray(long long int A[MAX],long long int low,long long int high,long long int M){

		if(high == low){
	return A[low];
		}
		else{
			long long int mid = (low+high)/2;
			long long int left_modulo_sum = find_max_modulo_subarray(A,low,mid,M);
			//cout<<left_modulo_sum<<endl;
			long long int right_modulo_sum = find_max_modulo_subarray(A,mid+1,high,M);
			//cout<<right_modulo_sum<<endl;
			long long int cross_modulo_sum = find_max_crossing_subarray(A,low,mid,high,M);
			//cout<<cross_modulo_sum<<endl;
			if(left_modulo_sum >= right_modulo_sum && left_modulo_sum >= cross_modulo_sum){
			return left_modulo_sum; }
			else if(right_modulo_sum >= left_modulo_sum  && right_modulo_sum >= cross_modulo_sum )
			{return right_modulo_sum;}

			else{
				return cross_modulo_sum;
			}
			
		}
	}