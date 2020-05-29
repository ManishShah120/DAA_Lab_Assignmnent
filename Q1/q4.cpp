//Sorting Techniques
//Finding kth minimum and maximum element in Heap.

#include <bits/stdc++.h> 
using namespace std; 


struct Heap { 
	vector<int> v; 
	int n;

	Heap(int i = 0) 
		: n(i) 
	{ 
		v = vector<int>(n); 
	} 
}; 
 
void swap(int& a, int& b) 
{ 
	int temp = a; 
	a = b; 
	b = temp; 
} 


inline int parent(int i) 
{ 
	return (i - 1) / 2; 
} 


inline int left(int i) 
{ 
	return 2 * i + 1; 
} 

inline int right(int i) 
{ 
	return 2 * i + 2; 
} 

void heapify(Heap& h, int i) 
{ 
	int l = left(i), r = right(i), m = i; 
	if (l < h.n && h.v[i] > h.v[l]) 
		m = l; 
	if (r < h.n && h.v[m] > h.v[r]) 
		m = r; 
	if (m != i) { 
		swap(h.v[m], h.v[i]); 
		heapify(h, m); 
	} 
} 

int extractMin(Heap& h) 
{ 
	if (!h.n) 
		return -1; 
	int m = h.v[0]; 
	h.v[0] = h.v[h.n-- - 1]; 
	heapify(h, 0); 
	return m; 
} 

int findKthSmalles(Heap &h, int k) 
{ 
	for (int i = 1; i < k; ++i) 
		extractMin(h); 
	return extractMin(h); 
} 

int extractMax(Heap& h) 
{ 
    if (!h.n) 
        return -1; 
    int m = h.v[0]; 
    h.v[0] = h.v[h.n-- - 1]; 
    heapify(h, 0); 
    return m; 
} 
  
int findkThGreatest(Heap &h, int k) 
{ 
    for (int i = 1; i < k; ++i) 
        extractMax(h); 
    return extractMax(h); 
}

int main() 
{ 
	int k,choice;
	Heap h(7); 
	h.v = vector<int>{ 10, 50, 40, 75, 60, 65, 45 };
	cout<<"1. K^th Minimum\n2. K^th Maximum\nChoice: ";
	cin>>choice;
	cout<<"Enter K: ";
	cin>>k;
	if(choice == 1)
		cout<<findKthSmalles(h, k)<<"\n"; 
	else
		cout<<findkThGreatest(h, k)<<"\n"; 
	return 0; 
}
