//Sorting Techniques
//Delete kth indexed element in Min heap and Max heap.
#include<iostream>
using namespace std;
#define max_val 9999

void restoreup(int arr[], int loc);
void buildheap(int arr[],int hsize);
void restoredown(int arr[], int i, int size);
int del_root(int arr[], int *p_hsize);
void display(int arr[], int hsize);

int main()
{
	int arr[100];
	int hsize = 0;
	int choice,num;
	arr[0] = max_val;
	
	while(1)
	{
		cout<<"\n1. Delete\n"
		    <<"2. Display\n"
		    <<"3. Build heap\n"
		    <<"4. Exit\n"
		    <<"Enter your choice: ";
		cin>>choice;

		switch(choice)
		{
		  case 1:
		  	if(hsize == 0)
		  		cout<<"heap is empty";
		  	else
		  		{
		  			num = del_root(arr, &hsize);
		  			cout<<"maximum element is "<<num<<endl;
		  		}
		  	break;
		  case 2:
		  	display(arr,hsize);
		  	break;
		  case 3:
		  	cout<<"enter size of the array: ";
		  	cin>>hsize;
		  	cout<<"enter the array elements: ";
		  	for(int i=1; i<=hsize; i++)
		  		cin>>arr[i];
		  	buildheap(arr, hsize);
		  	break;
		  case 4:
		  	exit(1);
		  default:
		  	cout<<"wrong choice\n";
		}
	}
	return 0;
}

void display(int arr[], int hsize)
{
	int i;
	if(hsize == 0)
	{
		cout<<"Heap is empty";
		return;
	}
	
	for(i =1; i<=hsize; i++)
		cout<<arr[i]<<" ";
	cout<<"\nNumber of elements: "<<hsize;	
}

void restoreup(int arr[], int i)
{
	int k = arr[i];
	int par = i/2;
	
	while(arr[par] < k)
	{
		arr[i] = arr[par];
		i = par;
		par = i/2;
	}
	arr[i] = k;
}

void restoredown(int arr[], int i, int hsize)
{
	int lchild = 2*i;
	int rchild = lchild+1;
	int num = arr[i];
	
	while(rchild <= hsize)
	{
		if(num >= arr[lchild] && num >= arr[rchild])
		{
			arr[i] = num;
			return;
		}
		else if(arr[lchild] > arr[rchild])
		{
			arr[i] = arr[lchild];
			i = lchild;
		}
		else
		{
			arr[i] = arr[rchild];
			i = rchild;
		}
		lchild = 2*i;
		rchild = lchild + 1;
	}
	
	//if number of node is even
	if(lchild == hsize && num < arr[lchild])
	{
		arr[i] = arr[lchild];
		i = lchild;
	}
	arr[i] = num;
}

int del_root(int arr[], int *p_hsize)
{
	int max = arr[1];	//save the element present at the root
	arr[1] = arr[*p_hsize];	//place the last elelement in the root
	(*p_hsize)--;	//decrease the heap size by 1
	restoredown(arr, 1, *p_hsize);
	return max;
}

void buildheap(int arr[], int size)
{
	int i;
	for(i=2; i<= size; i++)
		restoreup(arr, i);
}


