//sorting techniques
//build min heap, max heap and sort the given elements.
#include <iostream>
using namespace std;

//--------------------------
void MaxHeapify(int arr[], int i, int n) 
{ 
	int l = 2*i + 1; 
	int r = 2*i + 2; 
	int largest = i; 
	if (l < n && arr[l] > arr[i]) 
		largest = l; 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 
	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		MaxHeapify(arr, largest, n); 
	}
} 

void build_maxheap(int arr[], int n) 
{ 
	for (int i = (n-2)/2; i >= 0; --i) 
		MaxHeapify(arr, i, n); 
} 

//-----------------------------

void MinHeapify(int *a,int i,int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j+1] < a[j])
			j = j + 1;
		if (temp < a[j])
			break;
		else if (temp >= a[j])
		{
			a[j/2] = a[j];
			j = 2 * j;
		}
	}
	a[j/2] = temp;
	return;
}

void build_minheap(int *a, int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MinHeapify(a,i,n);
}
//-----------------------
void heapify(int arr[], int n, int i) 
{ 
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
  
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
  
   
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
  
    
    if (smallest != i) { 
        swap(arr[i], arr[smallest]); 
        heapify(arr, n, smallest); 
    } 
} 
  
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i = n - 1; i >= 0; i--) { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 

int main()
{
	int n, i, x,choice;
	int *a;
	cout<<"Enter no of elements of array: ";
	cin>>n;
	a = new int[n];
	
	cout<<"Enter "<<n<<" Elements:\n";
	for (i = 1; i <= n; i++)
		cin>>a[i];
	
	cout<<"1. Build MinHeap\n2. Build MaxHeap\nChoice: ";
	cin>>choice;
	if (choice == 1) {
		build_minheap(a, n);
		cout<<"Min heap\n";
		for (i = 0; i < n; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	else {
		build_maxheap(a,n);
		cout<<"Max heap\n";
		for (i = 0; i < n; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	
	cout<<"\nSorted array:\n";
	heapSort(a, n);
	for (int i = 0; i < n; i++) 
		cout << a[i] << " "; 
	cout << "\n";
	return 0;
}
