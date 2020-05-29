//Sorting Techniques
//Implement the ascending and descending order using Quick Sort.
#include<iostream>
using namespace std;
int choice;

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ShowElements(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int Partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low-1);
	
	for(int j = low; j<=high-1; j++)
	{
		if (choice == 1)
		{
			if(arr[j] < pivot)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		else
		{
			if(arr[j] > pivot)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

void QuickSort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pi = Partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi+1, high);
	}
}

int main()
{
	int n;
	int *arr;

	cout<<"Enter the size of the array: ";
	cin>>n;

	arr = new int[n];

	cout<<"Enter the elements: \n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"Entered Elements are: \n";
	ShowElements(arr, n);

	cout<<"\n1.Ascending\n2.Descending\nChosse:";
	cin>>choice;

	QuickSort(arr, 0, n-1);

	cout<<"After Sorting\n";
	ShowElements(arr, n);

	return 0;
}
