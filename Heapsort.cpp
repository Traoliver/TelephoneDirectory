#include <iostream> 
#include "DanhBa.cpp"
using namespace std; 
  
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
#ifndef Heap
#define Heap
		void heapify(DanhBa arr[], int n, int i, bool increas,int choise) 
{ 
	    int smallest = i; // Initialize smalles as root 
	    int l = 2 * i + 1; // left = 2*i + 1 
	    int r = 2 * i + 2; // right = 2*i + 2 
	  
	    // If left child is smaller than root 
	    if (l < n && sortDirectory (arr[l] , arr[smallest],choise ) == increas ) 
	        smallest = l; 
	  
	    // If right child is smaller than smallest so far 
	    if (r < n && sortDirectory (arr[r] , arr[smallest],choise ) == increas) 
	        smallest = r; 
	  
	    // If smallest is not root 
	    if (smallest != i) { 
	        swap(arr[i], arr[smallest]); 
	  
	        // Recursively heapify the affected sub-tree 
	        heapify(arr, n,smallest,increas,choise); 
	    } 
	} 
  
// main function to do heap sort 
	void heapSort(DanhBa arr[], int n, bool increas, int choise) 
	{ 
		int m = n/2 -1;
	    // Build heap (rearrange array) 
	    for (int i = m; i >= 0; i--) 
	        heapify(arr, n, i,increas,choise); 
	  	 m = n - 1;
	    // One by one extract an element from heap 
	    for (int i = m; i >= 0; i--) { 
	        // Move current root to end 
	        swap(arr[0], arr[i]); 
	  
	        // call max heapify on the reduced heap 
	        heapify(arr, i, 0,increas,choise); 
	    } 
	} 
 #endif Heap
