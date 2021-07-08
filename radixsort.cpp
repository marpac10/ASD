#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include <sys/time.h>
using namespace std; 
  
// A utility function to get maximum value in arr[] 

  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 

void countingSort(int A[], int n, int d) 
{ 
    int B[n]; 
    int i, C[10] = {0}; 
  
     
    for (i = 0; i < n; i++) 
        C[ (A[i]/d)%10 ]++; 
  
    
    for (i = 1; i < 10; i++) 
        C[i] += C[i - 1]; 
  
    
    for (i = n - 1; i >= 0; i--) 
    { 
        B[C[ (A[i]/d)%10 ] - 1] = A[i]; 
        C[ (A[i]/d)%10 ]--; 
    } 
  
    
    for (i = 0; i < n; i++) 
        A[i] = B[i]; 
} 
   
void radixsort(int A[], int n, int k) 
{ 
   
  for (int d = 1; k/d > 0; d *= 10) 
        countingSort(A, n, d); 
} 
  
// A utility function to print an array 
void stampa(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver program to test above functions 
int main() 
{ 
int n,k;
   cout << "Inserisci il numero di elementi da ordinare: \n";
   cin >> n;
   int A[n];     
    
   cout << "Inserisci la cardinalita' dell'insieme degli elementi : \n";
   cin >> k;
   srand(111222333);
  
   for(int i = 0; i<n; i++) {
       A[i] = rand() % k;
   }
   
   
   cout << "Vettore A (non ordinato) : ";
   stampa(A, n);
   

timeval start, stop;
double elapsedTime;

gettimeofday(&start, NULL);

  radixsort(A, n, k); 
   
gettimeofday(&stop, NULL);

elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;               // sec to ms
elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;            // us to ms

cout << "Vettore  (ordinato) : ";
   stampa(A, n);
   
cout  << "\n il tempo di esecuzione e' :  " << elapsedTime << " ms.\n";
     
    return 0; 
} 
