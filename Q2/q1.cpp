//2 Greedy Algorithms
//1. Implement the job sequencing with deadlines problem using the fixed tuple size formulation.
#include<iostream> 
#include<algorithm> 
using namespace std; 

struct Job 
{
	char id[3]; 
	int deadline; 
	int profit;
};

bool comparison(Job a, Job b) 
{
	return (a.profit > b.profit); 
}

void printJobScheduling(Job arr[], int n) 
{
	int sumofProfits = 0;
	sort(arr, arr+n, comparison); 
	int result[n];
	bool slot[n]; 

	for (int i=0; i<n; i++) 
		slot[i] = false;

	for (int i=0; i<n; i++) 
    	{

		for (int j=min(n, arr[i].deadline)-1; j>=0; j--) 
		{ 
			if (slot[j]==false) 
			{
				result[j] = i;
				slot[j] = true;
				break; 
			}
		}
	}

	for (int i=0; i<n; i++) {
		if (slot[i]) {
			cout<<arr[result[i]].id << " ";
			sumofProfits = sumofProfits + arr[result[i]].profit;
		}
	}
	cout<<"\nTotal Profit: "<<sumofProfits<<"\n";
}

int main() 
{
	Job arr[] = { {"J1", 7, 15}, {"J2", 2, 20}, {"J3", 5, 30}, {"J4", 3, 18}, {"J5", 4, 18}, {"J6", 5, 10}, {"J7", 2, 23}, {"J8", 7, 16}, {"J9", 3, 25} };
         
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Profit sequence of jobs: "; 
	printJobScheduling(arr, n);
	cout<<endl;
	return 0; 
}
