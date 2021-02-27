#include <stdio.h>

void swap(int arr[] , int i , int j){
	int temp = arr[i];
	arr[i]=arr[j];
	arr[j] = temp;
}
//-------------------------------------

//Selection Sort
void selection(int arr[],int n){
	for(int i=0 ; i<n-1 ; i++){
		int min = i;
		for(int j=i+1 ; j<n ; j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		swap(arr,i,min);
	}
}
//-------------------------------------

//Insertion Sort
void insertion(int arr[],int n){
	for(int i=1 ; i<n ; i++){
		int j=i;
		while((arr[j-1]>arr[j] && j>0)){
			swap(arr,j,j-1);
			j--;
		}
	}
}
//-------------------------------------

//Bubble Sort
void bubble(int arr[],int n){
	for(int i=0 ; i<n-1 ; i++){
		for(int j=0 ; j<n-i-1 ; j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
			}
		}
	}
}
//-------------------------------------

//Quick Sort
int partition(int arr[],int low , int high){
	int i = low-1;
	int piv = high;
	for(int j=low ; j<high ; j++){
		if(arr[j]<arr[piv]){
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,high);
	return i+1;
}

void quicksort(int arr[],int low, int high){
	if(low<high){
		int p = partition(arr,low,high);
		quicksort(arr,low,p-1);
		quicksort(arr,p+1,high);
	}
}
//-------------------------------------

//Merge Sort
void merge(int arr[] , int l , int m , int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int i,j,k;
	int L[n1] , R[n2];

	for(i=0 ; i<n1 ; i++){
		L[i]=arr[l+i];
	}
	for(j=0 ; j<n2 ; j++){
		R[j]=arr[m+j+1];
	}

	i=0;
	j=0;
	k=l;

	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
}

void mergesort(int arr[] , int l , int r){
	if(l<r){
		int m = (l+r)/2;
		mergesort(arr, l, m);
		mergesort(arr, m+1, r);
		merge(arr,l,m,r);
	}
}
//-------------------------------------

//Heap Sort
//-------------------------------------
void heapify(int arr[] , int n , int i){
	int largest=i;
	int lc = (2*i)+1;
	int rc = (2*i)+2;

	if(lc<n && arr[largest]<arr[lc]){
		largest=lc;
	}
	if(rc<n && arr[largest]<arr[rc]){
		largest=rc;
	}
	if(i!=largest){
		swap(arr,i,largest);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[] , int n){
	for(int i=(n/2)-1 ; i>=0 ; i-- ){
		heapify(arr,n,1);
	}

	for(int i=n-1 ; i>=0 ; i-- ){
		swap(arr,0,i);
		heapify(arr,i,0);
	}
}
//-------------------------------------

void display(int arr[],int n){
	printf("\nSorted Array: ");
	for(int i=0 ; i<n ; i++){
		printf("%d\t",arr[i]);
	}
}

int main(void) {
	int arr[] = {5,4,3,2,1};
	heapsort(arr,5);
	display(arr,5);
	return 0;
}