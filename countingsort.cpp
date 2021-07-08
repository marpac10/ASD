#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include <sys/time.h>

using namespace std;

void stampa(int *array, int dim) {
   for(int i = 1; i<=dim; i++)
      cout << array[i] << " ";
   cout << endl;
}


void countingSort(int *A, int* B, int dim, int k) {

   int C[k+1];     
   for(int i = 0; i<k; i++)
      C[i] = 0;     
   for(int i = 1; i <=dim; i++)
      C[A[i]]++;     
   for(int i = 1; i< k; i++)
      C[i] = C[i]+C[i-1];     
   for(int i = dim; i>=1; i--) {
      B[C[A[i]]] = A[i];
      C[A[i]] = C[A[i]] - 1; 
   }
   
}

int main() {
   
   int n,k;
   cout << "Inserisci il numero di elementi da ordinare: \n";
   cin >> n;
   int A[n+1];     
   int B[n+1];  
   cout << "Inserisci la cardinalita' dell'insieme degli elementi : \n";
   cin >> k;
   srand(111222333);
   //cout << "Inserisci gli elementi:" << endl;
   for(int i = 1; i<=n; i++) {
       A[i] = rand() % k;
   }
   
   
   cout << "Vettore A (non ordinato) : ";
   stampa(A, n);
   

timeval start, stop;
double elapsedTime;

//da dare prima del codice su cui si vuole fare il test, per registrare il tempo di avvio
gettimeofday(&start, NULL);


  int C[k+1];     
   for(int i = 0; i<k; i++)
      C[i] = 0;     
   for(int i = 1; i <=n; i++)
      C[A[i]]++;     
   for(int i = 1; i< k; i++)
      C[i] = C[i]+C[i-1];     
   for(int i = n; i>=1; i--) {
      B[C[A[i]]] = A[i];
      C[A[i]] = C[A[i]] - 1; 
  }
   
//qui si riprende il tempo finale per fare la differenze
gettimeofday(&stop, NULL);

//calcolo delle differenze
elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;               // sec to ms
elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;            // us to ms

//stampa
cout << "Vettore B (ordinato) : ";
  stampa(B, n);
   
cout  << " il tempo di esecuzione e' :  " << elapsedTime << " ms.\n";
 
}


