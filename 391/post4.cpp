#include <cstdlib>
#include <iostream>
using namespace std;

void merge(int *A, int kiri, int tengah, int kanan){
	int B[kiri+kanan];
	int i, kidal1, kidal2;
	kidal1=kiri;
	kidal2=tengah+1;
	i=kiri;
	while(kidal1<=tengah && kidal2<=kanan){
		if(A[kidal1]<=A[kidal2]){
			B[i]=A[kidal1];
			kidal1++;
		}
		else{
			B[i]=A[kidal2];
			kidal2++;
		}
		i++;
	}
	while(kidal1<=tengah){
		B[i]=A[kidal1];
		kidal1++;
		i++;
	}
	while(kidal2<=kanan){
		B[i]=A[kidal2];
		kidal2++;
		i++;
	}
	for(int i=kiri; i<=kanan; i++){
		A[i]=B[i];
	}
}
void mergesort(int *A, int i, int j){
	int k;
	if(i<j){
		k=((i+j)/2);
		mergesort(A, i, k);
		mergesort(A, k+1, j);
		merge(A, i,k, j);
	}
}

int main(int argc, char *argv[]){
	int n;
	int i;
	int j;
	cout<<"mergesort dengan divide and conquer"<<endl<<endl;
	cout<<"banyak data : ";
	cin>>n;
	i=1;
	j=n;
	int A[n];
	for(int x=1; x<=n; x++){
		cout<<"masukkan data ke- "<<x<<" ";
		cin>>A[x];
	}
	cout<<"data sebelum diurutkan"<<endl;
	for(int x=1; x<=j; x++){
		cout<<A[x]<<" ";
	}
	cout<<endl;
	mergesort(A, i, j);
	cout<<"data setelah diurutkan"<<endl;
	for(int x=1; x<=j; x++){
		cout<<A[x]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}