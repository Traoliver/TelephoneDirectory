#include<iostream.h>
#include<conio.h>
#include "DanhBa.cpp"
using namespace std;
void merge(DanhBa arr[], int l, int m, int r, bool increase , int choise) 
{ 
    int i, j; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    DanhBa L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
   int k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2){ 
        if (sortDirectory (L[i] , R[j] ,choise) == increase){ 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2){ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
//	printArray(arr,7);
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(DanhBa arr[], int l, int r, bool increase ,int choise) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m,increase,  choise); 
    //  cout<<" left: "<<l<<" "<<m<<endl;
        mergeSort(arr, m+1, r,increase, choise); 
	//	cout<<" right: "<<l<<" "<<m+1<<endl;
        merge(arr, l, m, r,increase, choise); 
    } 
//	printArray(arr,7);
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */

  
/* Driver program to test above functions */
/*int main() 
{ 
    int arr[] = {1200, 11, 13, 5, 6, 7,9}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
//  	cout<<" size of array "<<sizeof(arr);
// 	cout<<" size of array a[0]"<<sizeof(arr[0]); 
    printf("\nGiven array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1,false); 
  
    cout<<"\nSorted array is \n"; 
    printArray(arr, arr_size); 
    return 0; 
} */
