//Sorting Techniques
//Implement Quick Sort using first/last/any random element as pivot.
#include<iostream>
using namespace std;

void Swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ShowElements(int arr[], int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i];
		cout<<"\t";
	}
	cout<<"\n";
}

int partition (int arr[], int low, int high) { 
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++) {
		if (arr[j] < pivot) {
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

int main() {
	int *arr, n;
	
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements: \n";
	arr = new int[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	
	cout<<"Entered Elements are:\n";
	ShowElements(arr, n);
	
	QuickSort(arr, 0, n-1);
	
	cout<<"After Sorting\n";
	ShowElements(arr, n);
	
	return 0;
}
