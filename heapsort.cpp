#include<iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && a[l]>a[largest])
        largest = l;
    if(r<n && a[r]>a[largest])
        largest = r;
    if(largest != i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

void heapsort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for (int i = n - 1; i >= 0; i--) 
    {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int main() 
{
    int arr[6] = {10,80,50,20,35,15};
    heapsort(arr,6);
    for(int i=0; i<6; i++)
        cout << arr[i] << " ";
    return 0;
}