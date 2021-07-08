#include <iostream> 
#include <algorithm> 
#include <vector> 
#include<stdlib.h>
#include <sys/time.h>
using namespace std; 
  
  
  void stampa(float arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 

void InsertionSort (float A[], int n)
{
for (int j=1; j<n; j++)
{
float key = A[j];
// Insert A[j] into A[1..j-1]
int i = j-1;
while (i>=0 && A[i]>key)
{
A[i+1] = A[i];
i--;
}
A[i+1] = key;
}
}

 
void bucketSort(float A[], int n) 
{ 
    float* b[n]; 
     
    for (int i=0; i<n; i++) 
    { 
       int bi = n*A[i]; 
       b[bi].push_back(A[i]); 
    } 
  
    
    for (int i=0; i<n; i++) 
       //InsertionSort(b[i],b[i].size());  
       sort(b[i].begin(), b[i].end()); 
   
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
          A[index++] = b[i][j]; 
} 
  
/* Driver program to test above funtion */
int main() 
{ 
int n,k;
   cout << "Inserisci il numero di elementi da ordinare: \n";
   cin >> n;
   float A[n];     
   srand(111222333);
   
   for(int i = 0; i<n; i++) {
       A[i] = float(rand() % 100)/ 100.0;
   }
   
  // cout << "Vettore A (non ordinato) : ";
   //stampa(A, n);
   
timeval start, stop;
double elapsedTime;

gettimeofday(&start, NULL);

  bucketSort(A, n); 
   
gettimeofday(&stop, NULL);

elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;               // sec to ms
elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;            // us to ms

//cout << "Vettore  (ordinato) : ";
  // stampa(A, n);
   
cout  << "\n il tempo di esecuzione e' :  " << elapsedTime << " ms.\n";
     
    return 0; 
} 
