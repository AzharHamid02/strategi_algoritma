#include <cstdlib>
#include <iostream>
using namespace std;

typedef int larik [10]; //tipe data untuk merge
void baca_data(int A[], int n){
	//proses input dan baca data
	for(int i=0; i<n; i++){
		cout<<"Data ke - "<<i+1<<" : ";
		cin >> A[i];
	}
}

void cetak_data(int A[], int n){
	//cetak data
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
}

void tukar_data(int *a, int *b){
	//tukar data
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void minimum(int A[], int dari, int n, int *tempat){
	int i, min;
	min=A[dari];
	*tempat=dari;
	for(i=dari+1; i<n; i++)
		if(A[i]<min){
			min=A[i];
			*tempat=i;
		}
}

void bubble_sort(int x[], int n){
	//bubble sort
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(x[i]>x[j])
				tukar_data(&x[i], &x[j]);
		}
	}
}

void selection_sort(int A[], int n){
	//sellection sort
	int i, t;
	for(i=0; i<n; i++){
		minimum(A, i, n, &t);
		tukar_data(&A[i], &A[t]);
	}
}

void merge(larik a, int kiri, int tengah, int kanan){
	int bagkir, postemp, bykel, i;
	larik temp;
	bagkir=tengah-1;
	postemp=kiri;
	bykel=kanan-kiri+1;
	while((kiri<=bagkir) && (tengah<=kanan)){
		if((a[kiri]<=a[tengah])){
			temp[postemp]=a[kiri];
			postemp=postemp+1;
			kiri=kiri+1;
		}
		else{
			temp[postemp]=a[tengah];
			postemp=postemp+1;
			tengah=tengah+1;
		}
		//kopi bagian kiri
		while((kiri<=bagkir)){
			temp[postemp]=a[kiri];
			postemp=postemp+1;
			kiri=kiri+1;
		}
		//kopi bagian kanan
		while((tengah<=kanan)){
			temp[postemp]=a[tengah];
			postemp=postemp+1;
			tengah=tengah+1;
		}
		//kopi ke aaray asal
		for(i=1; i<=bykel; i++){
			a[kanan]=temp[kanan];
			kanan=kanan-1;
		}
	}
}

void merge_sort(larik A, int kiri, int kanan){
	int tengah;
	if(kiri<kanan){
		tengah=(kiri + kanan)/2;
		merge_sort(A, kiri, tengah);
		merge_sort(A, tengah+1, kanan);
		merge(A, kiri, tengah+1, kanan);
	}
}

int partisi(int A[], int rendah, int tinggi){
	int pivot=A[tinggi];
	int i=(rendah-1);
	
	for(int j=rendah; j<tinggi; j++){
		if(A[j]<=pivot){
			i++;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	int temp=A[i+1];
	A[i+1]=A[tinggi];
	A[tinggi]=temp;
	return(i+1);
}

void QuickSort(int A[], int rendah, int tinggi){
    if(rendah < tinggi){
        int Partisi = partisi(A, rendah, tinggi);
        QuickSort(A, rendah, Partisi-1);
        QuickSort(A, Partisi+1, tinggi);
    }
}

int main(int argc, char *argv[]){
	int data[10], n;
	int pilih;
	t1:
		cout<<"1. Bubble Sort\n2. Selection Sort\n3. Merge Sort\n4. Quick Sort\n\n";
		cout<<"Pilihan : ";
		cin>>pilih;
		switch(pilih){
			case 1://bubble sort
				cout<<"BUBBLE SORT";
				cout<<"\n\nMasukan data : ";
				cin>>n;
				baca_data(data, n);
				cout<<"Data yang anda masukan : ";
				cetak_data(data, n);
				cout<<endl;
				bubble_sort(data, n);
				cout<<"Setelah ditukar (Bubble Sort) : ";
				cetak_data(data, n);
				cout<<endl;
				break;
			case 2://selection sort
				cout<<"SELECTION SORT";
				cout<<"\n\nMasukan data : ";
				cin>>n;
				baca_data(data, n);
				cout<<"Data yang anda masukan : ";
				cetak_data(data, n);
				cout<<endl;
				selection_sort(data, n);
				cout<<"Setelah ditukar (Selection Sort): ";
				cetak_data(data, n);
				cout<<endl;
				break;
			case 3://merge sort
				cout<<"MERGE SORT";
				cout<<"\n\nMasukan data : ";
				cin>>n;
				baca_data(data, n);
				cout<<"Data yang anda masukan : ";
				cetak_data(data, n);
				cout<<endl;
				merge_sort(data, 0, n-1);
				cout<<"Setelah ditukar (Merge Sort): ";
				cetak_data(data, n);
				cout<<endl;
				break;
			default:
				cout<<"Ulangi !\n";
				goto t1;
		}
		system("PAUSE");
		return EXIT_SUCCESS;
}