#include<stdio.h>
#include<iostream>
using namespace std;

int merge1(int arr[],int l,int m,int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L1[n1], R1[n2];
 
    for(i = 0; i < n1; i++)
        L1[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R1[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j])
        {
            arr[k] = L1[i];
            i++;
        }
        else
        {
            arr[k] = R1[j];
            j++;
        }
        k++;
    }
 

    while (i < n1)
    {
        arr[k] = L1[i];
        i++;
        k++;
    }
 
 
    while (j < n2)
    {
        arr[k] = R1[j];
        j++;
        k++;
    }	
}

int mergesort(int a[],int l,int r)
{
     if (l < r)
    {
        int m = l+(r-l)/2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge1(a, l, m, r);
    }	
}


int main()
{
	int n;
	cin>>n;
	
	int *a=new int[n];
	 
	for(int i=0;i<n;i++)
	    cin>>a[i];
	
	mergesort(a,0,n-1);
	
	cout<<"\nSorted Array:";
	for(int i=0;i<n;i++)
	  cout<<a[i]<<',';    
}